#include <iostream>
#include <stdlib.h>
#define MAX 1000
using namespace std;

int ans;
int TOP;
int STACK[MAX];

int add(int a,int b){
    ans=a+b;
    return ans;
}

int sub(int a,int b){
    ans=a-b;
    return ans;
}

int mul(int a,int b){
    ans=a*b;
    return ans;
}

int divide(int a,int b){
    ans=a/b;
    return ans;
}
 
void initStack(){
    TOP=-1;
}

int isEmpty(){
    if(TOP==-1)
        return 1;
    else
        return 0;
}
 
int isFull(){
    if(TOP==MAX-1)
        return 1;
    else   
        return 0;
}
 
void push(int num){
    if(isFull()){
        cout<<"STACK is FULL."<<endl;
        return; 
    }
    ++TOP;
    STACK[TOP]=num;
}a
 
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
 
/*int main()
{
    initStack();
    int firstNumber, secondNumber, answer, output;
    char input;
    cout << "Instructions:\n\nPress + to add\nPress - to subtract\nPress * to multiply\nPress / to divide\nPress c to clear\nPress m to save\n " ;
    cin >> firstNumber >> input >>secondNumber;
    if(input =='+'){
        output=add(firstNumber,secondNumber);
    }
    else if(input == '-'){
        output=sub(firstNumber,secondNumber);
    }
    else if(input == '*'){
        output=mul(firstNumber,secondNumber);
    }
   else if(input == '/'){
        output=divide(firstNumber,secondNumber);
    }
    else if(input == 'c'){
        exit(0);
    }
    
    cout << output;
    
    for(;;){
        char input1;
        int number;
        cin >> input1;
        if(input1 == 'c'){
            display();
            exit(0);
        }
        else if(input1 == '+'){
            cin >> number;
            output=add(output,number);
        }
        
        else if(input1 == '-'){
            cin >> number;
            output=sub(output,number);
        }
        else if(input1 == '*'){
            cin >> number;
            output=mul(output,number);
        }
        else if(input1 == '/'){
            cin >> number;
            output=divide(output,number);
        }
        else if(input1 == 'm'){
            push(output);
        }
       cout<<output;
    }
    
    return 0;
}*/