 ## Importance of C standards ##

**Standard** is important because of the following things:-

1. Tells us all the new features added from other languages.
2. Specifies the old features which are improved.
3. Security Enhancement.

The **Five** important c standards in their usage order are:

1. K&R C (Earliest C standard)
2. ANSI C
3. C99
4. C11 (Latest Standard )
5. Embedded C (Parallel development)

The command **info gcc** will tell you about the current default standard of gcc, which can also be obtained with the option **-std=gnu90**.

The C standards committee responsible for making the decisions regarding C standardisation is called **ISO/IEC JTC 1/SC 22/WG 14**. It is a standardisation subcommittee of the Joint Technical Committee ISO/IEC JTC 1 of the International Organization for Standardization (ISO) and the International Electrotechnical Commission (IEC).  

Now let's focus on some important standards.

####C99####

C99 is the informal name given to the ISO/IEC 9899:1999 standards specification for C that was adopted in 1999. The C99 standard added **five more keywords** to ANSI C, and the total number of keywords became **37**. 

The keywords added in C99 are:-

1. _Bool --> To declare a new integer type capable of storing 0 and 1.
2. _Complex -->To declare complex and imaginary floating point type variables to handle complex numbers
3. _Imaginary -->To declare complex and imaginary floating point type variables to handle complex numbers
4. inline --> To declare inline functions in C, similar to C++ inline functions.
5. restrict --> TTo tell the compiler that for the lifetime of the pointer, only the pointer itself or a value directly derived from it will be used to access the object to which it points.


 **New header files** like <stdbool.h>, <complex.h>, <tgmath.h>, <inttypes.h>, etc, were also added in C99. A new integer data type called **long long int** with a minimum size of 8 bytes was added in C99.

Some improved programs then ANSI C standards:-

In gcc compiler **long long int** usually takes 8 bytes. The C99 program named fact.c given below finds the factorial of 20. A program using the data type long int with the usual minimum size of 4 bytes would have given the answer as -2102132736 due to overflow.

	#include<stdio.h>
	int main( )
	{
	long long int f=1;
	int a=20,i=1;
	for(i=1; i<=a; i++)
	{
	f = f * i;
	}
	printf(“the factorial is %lld\n”, f);
	return 0;
	}

The program can be compiled by executing the command gcc -std=c99 fact.c or the command gcc fact.c on the terminal. The second command works because, by default, gcc compiler supports long long int. The output of the C99 program is 2432902008176640000.
So rectified bug in earlier standard.

####C11####

C11 is the latest standard in C and as the name suggests it was launched in 2011. In C11 seven mre keywords were added and these are:-

1. _Alignas
2. _Alignof
3. _Atomic
4. _Generic
5. _Noreturn
6. _Static_assert
7. _Thread_local. 

So after this standard their are total 44 standards in C. Now let's see usage of one of these keyword, Let's take _Noreturn.

        #include<stdio.h>
        
        _Noreturn fun( )
        {
         printf("\nI TOO WILL BE PRINTED :) \n\n");
          }
 
        int main( )
		{
		printf("\nI WILL BE PRINTED :) \n");
		fun( ); 
		printf("\nI WILL NOT BE PRINTED :( WHY? \n");
		}

So now the output of this will have only "I will be printed " and "I too will be printed"

_Noreturn function terminates the main function and exits code unlike void return type.


###Embedded C###

The Embedded C standard was proposed to **customize the C language** in such a way that it can cater to the needs of embedded system programmers. While the other standards of C are improvements over previous standards, Embedded C is a standard that is being **developed in parallel**. 

Embedded C mostly has the syntax and semantics of normal C with additional features like:- 

* Fixed-point arithmetic
* named address spaces
* basic I/O hardware addressing. 

The main advantage of the Embedded C standard is that it is simpler and easier to learn than traditional C.

###Difference between embedded C and normal c###

1. C is generally used for desktop computers, while embedded C is for microcontroller based applications.
2. C can use the resources of a desktop PC like memory, OS, etc. While, embedded C has to use with the limited resources, such as RAM, ROM, I/Os on an embedded processor.
3. Embedded C includes extra features over C, such as fixed point types, multiple memory areas, and I/O register mapping.
4. Compilers for C (ANSI C) typically generate OS dependant executables. Embedded C requires compilers to create files to be downloaded to the microcontrollers/microprocessors where it needs to run




   
