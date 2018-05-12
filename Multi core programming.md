## Multi core programming ##

### What is it and why do we use multi thread programming???###

**Single-threaded programs** execute one line of code at a time, then move onto the next line in sequential order. This is generally the default behaviour when you write code. 

**Multi-threaded** programs are executing from two or more locations in your program at the same time. 

For example, suppose you want to perform a long file download from the internet, but don’t want to keep the user waiting while this happens. Imagine how inconvenient it would be if we couldn’t browse other web pages while waiting for files to download! So, we create a new thread (in the browser program for example) to do the download. In the meantime, the main original thread keeps processing mouse clicks and keyboard input so you can continue using the browser. When the file download completes, the main thread is signaled so it knows about it and can notify the user visually, and the thread performing the download closes down.

###How does this work??###

 1. Application calls the system to request the creation of a new thread, along with the thread priority (how much processing time it is allowed to consume) and the starting point in the application that the thread should execute from (this is nearly always a function which you have defined in your application).

  2. Main application thread and secondary thread (plus any other created threads) run concurrently
  3. When the main thread’s work is done, or if at any point it needs to wait for the result of a secondary thread, it waits for the relevant thread(s) to finish. This is (misleadingly) called a **join operation**
  4. Secondary threads finish their work and may optionally signal to the main thread that their work is done (either by setting a flag variable, or calling a function on the main thread Secondary threads close down
  5. If the main thread was waiting on a join operation (see step 3), the termination of the secondary threads will cause the join to succeed and execution of the main thread will now resume
  
### Difference between single core and multi core milti prcessing

If your processor has multiple cores, and your operating system supports it, creating a new thread will (or may by default) cause the new thread to be executed on an unused or least busy core. Therefore, running ** multi-threaded applications on multi-core systems** is the primary way to take advantage of multiple cores and can enable a several-fold performance increase on complex tasks. If your application is multi-threaded, you can be mostly assured that it will automatically take advantage of multi-core processors. In contrast, on single-core processors, the threads will be time-sliced by the operating system in the same way processes are in a multi-tasking environment and all run on the single core, so there is no effective performance gain.

Note that there are laws of diminishing returns at work when using something like the parallel aggregation pattern: creating 4 worker threads will not necessarily lead to a 4-fold performance increase. Depending on the algorithms in use, the amount of co-ordination between threads, overhead from accessing memory shared between threads and other factors, the speed-up will be sub-linear.

### Multi core Programming in C ###

	void myThread1()
	{
  	while (true)
  	{
    // do some work
 
    // log it:
    std::cout << "Hello World" << std::endl;
 	 }
	}
 
	void myThread2()
	{
 		 while (true)
  	{
    // do some work
 
    // log it:
    std::cout << "The quick brown fox" << std::endl;
		}

The order of execution of the two threads, and when the threads get time-sliced and control passed to the other thread is unpredictable. This is acceptable and usually what you want, since the tasks are to run independently. You might expect an output like:

Hello World
Hello World
The quick brown fox
Hello World
The quick brown fox
The quick brown fox
The quick brown fox
Hello World
Hello World

or any other random combination of output of these two lines of text depending on how the threads are time-sliced. Unfortunately, things are not so simple. The thread may get time-sliced during the call to cout, and the other thread could output an entire line (or more) before the other thread’s call to cout is allowed to finish. This leads to weird output like this:

Hello WorThe quick brown fox
The quick brown fox
ld

This is almost certainly not what you want. Here the problem is quite harmless, but in real applications this can easily cause file or database corruption if two threads are writing to the same output (as they are above, writing to the console).

