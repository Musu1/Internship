/*Function: add
    Add two integers
  Parameters : 
    a - The first integer
    b - The second integer
  Return :
    Gives the addition of two numbers
*/ 

int functionResult;
int add(int a,int b){
    functionResult=a+b;
    return functionResult;
}

/*Function: sub
    Subtracts two integers
  Parameters : 
    a - The first integer
    b - The second integer
  Return :
    Gives the substraction of two numbers
*/

int sub(int a,int b){
    functionResult=a-b;
    return functionResult;
}

/*Function: mul
    Multiplies two integers
  Parameters : 
    a - The first integer
    b - The second integer
  Return :
    Gives the product of two numbers
*/

int mul(int a,int b){
    functionResult=a*b;
    return functionResult;
}

/*Function: div
    Divide two integers
  Parameters : 
    a - The first integer
    b - The second integer
  Return :
    Gives the division of two numbers
*/

int divide(int a,int b){
    float functionResult;
    functionResult=a/b;
    return functionResult;
}

/*Function: initStack
    Initializes a stack by initializing Top pointer as -1
  Parameters : 
    None required
*/
 
void initStack(){
    TOP=-1;
}

/*Function: isEmpty
    Checks wether the stack is empty or not
  Parameters : 
    None
  Return :
    Gives 1 if empty stack else 0
*/

int isEmpty(){
    if(TOP==-1)
        return 1;
    else
        return 0;
}
 
/*Function: isFull
    Check wether the stack is full or not
  Parameters : 
    None
  Return :
    Gives 1 if stackk is full or 0 if stack is empty
*/ 
int isFull(){
    if(TOP==MAX-1)
        return 1;
    else   
        return 0;
}

/*Function: push
    Adds a new integer in stack
  Parameters : 
    num - The number which you want to add in the stack.
*/
 
void push(int num){
    if(isFull()){
        cout<<"STACK is FULL."<<endl;
        return; 
    }
    ++TOP;
    STACK[TOP]=num;
}
 
 /*Function: display
    Add two integers
  Parameters : 
    None
  Return :
    Prints the stack.
*/

void display(){
    int i;
    cout<<"Your memory is:";
    if(isEmpty()){
        cout<<"Nothing in memory"<<endl;
        return;
    }
    for(i=TOP;i>=0;i--){
        cout<<STACK[i]<<" ";
    }
    cout<<endl;
}