#include<iostream># define MAX 1000

int functionResult;//output given by all the functions
int TOP;// Pointer used in stack
int STACK[MAX];//Stack with size 1000

class functions(){
    public:
/*Function: add
    Add two integers
  Parameters : 
    a - The first integer
    b - The second integer
  Return :
    Gives the addition of two numbers
*/ 

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
    functionResult=a/b;
    return functionResult;
}

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
        std::cout<<"STACK is FULL."<<std::endl;
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
    Prints the stack and if the stack is empty prints Nothing in Memory
*/

void display(){
    int i;
    std::cout<<"Your memory is:";
    if(isEmpty()){
        std::cout<<"Nothing in memory"<<std::endl;
        return;
    }
    for(i=TOP;i>=0;i--){
        std::cout<<STACK[i]<<" ";
    }
    std::cout<<std::endl;
}

/*
 Function: choose
    Chooses according the operation parameter which operation to be done
  Parameters : 
    firstNumber - The first number to be used in the operation
    secondNumber - The second number to be used in the operation
    operation - character can be =,-,/,*
  Return :
    the calculated output after the operation
 */
int choose(int firstNumber,int secondNumber, char operation){
    int output;
    if(operation =='+'){ //If operation is + then it will call the add function
        output=key.add(firstNumber,secondNumber);
    }
    else if(operation == '-'){//If operation is - then it will call the sub function 
        output=key.sub(firstNumber,secondNumber);
    }
    else if(operation == '*'){//If operation is * then it will call the mul function
        output=key.mul(firstNumber,secondNumber);
    }
   else if(operation == '/'){//If operation is / then it will call the divide function
        output=key.divide(firstNumber,secondNumber);
    }
    return output;
}