#include<stdio.h>

int functionResult;//output given by all the functions

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

float divide(float a,float b){
    float functionResult=a/b;
    return functionResult;
}