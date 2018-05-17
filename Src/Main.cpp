#include <iostream>
#include <stdlib.h>
#include "Function.cpp"

using namespace std;

int main()
{
    initStack();
    int firstNumber, secondNumber,output;
    char operation;
    cout << "Instructions:\n\nPress + to add\nPress - to subtract\nPress * to multiply\nPress / to divide\nPress c to clear\nPress m to save\n " ;
    cin >> firstNumber >> operation >>secondNumber;
    output=choose(firstNumber,secondNumber,operation);
    cout << output;
    for(;;){
        char continuosOperation;
        int UserSubsequentInput;
        cin >> continuosOperation;
        if(continuosOperation == 'c'){
        display();
        exit(0);
         }
        else if(continuosOperation == 'm'){
            push(output);
            continue;
        }
        cin >> UserSubsequentInput;
        output=choose(output,UserSubsequentInput,continuosOperation);
        cout<<output;
    }
    
    return 0;
}
