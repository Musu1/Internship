#include <iostream>
#include <stdlib.h>
#include "Function.cpp" //Include the function file

using namespace std;

int main()
{
    initStack();
    functions key;//creating object of class functions
    int firstNumber, secondNumber,output; // Things to be taken from the user
    char operation;
    // Providing basic instruction to the user
    cout << "Instructions:\n\nPress + to add\nPress - to subtract\nPress * to multiply\nPress / to divide\nPress c to clear\nPress m to save\n " ;
    cin >> firstNumber >> operation >>secondNumber;
    output=choose(firstNumber,secondNumber,operation); // Calling the choose function
    cout << output;
    for(;;){    //Infinite loop for continuing the operation with one operator
        char continuosOperation;
        int UserSubsequentInput;
        cin >> continuosOperation;
        if(continuosOperation == 'c'){ // Exit the code and display from the memory by calling the display function
        display();
        exit(0); // will make the code exit
         }
        else if(continuosOperation == 'm'){// Pushing the value in stack using push function
            push(output);
            continue; // continue with loop and will go to line 17 and sk for operator again
        }
        cin >> UserSubsequentInput;
        output=choose(output,UserSubsequentInput,continuosOperation);
        cout<<output; //Printing output for the user
    }
    
    return 0;
}
