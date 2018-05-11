#include<stdio.h>
#include<string.h>
#include<malloc.h>
//Created the structure of the node typedef struct node{ char a; struct node* next; }node;
//Print function
//Creating a temporary variable so that the original content is not destroyed while changing the referencing.
//see below link about ** in the pointers if any confusion is there.
//https://www.tutorialspoint.com/cprogramming/c_pointer_to_pointer.htm
void print(struct node **head){
struct node *temp = *head;
while(temp != NULL){
    printf("%c",temp->a);
    temp=temp->next;
}
}
//Creating the reverse function. You can use void or void static. You cannot create a function as a structure datatype and return a different value.
//Here instead of returning the pointer I have saved it to a location. If you want to return the pointer use the below function (in example).
//You can create a function that gets the pointer information. example below:
/*int * function(int a){
    int *var = malloc(sizeof(int)tags);
    //....
    return var;
}/
void reverse(struct node **head_ref){
struct node *prev = NULL, *current = NULL, *next = NULL;
while(current!= NULL){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
}
*head_ref = prev;
}
//Created a function to create a new node.
//Used new_node instead of root as in your example.
void push (struct node head_ref, char data) {
    struct node new_node = (struct node) malloc(sizeof(struct node));
    new_node->a = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
int main(){
char str[500];
int len,i;
printf("Enter a string\n");
//Using fgets instead of scanf because of the whilespace and new line character. Scanf discards anything after a whitespace or a newline character.
//gets can also be used but it have been deprecated so not using it.
/*Syntax of fgets
char *fgets(char *str, int n, FILE *stream)
here
char *str -> is the string or array where you want to store it.
int n -> maximum characters allowed in the string.
FILE *stread -> source of input. If using console then use stdin, if using a file put the file name.
*/
fgets(str,500, stdin);
printf("String is \n");
printf("%s", str);
len=strlen(str);
printf("String Length is %d\n", len);
//initializing the head as null so I can start pushing the data.
struct node* head = NULL;
for (i=0;i<len;i++)
{
    //Pushing data to the linked list.
    push(&head, str[i]);
    //The data would be displayed in reverse but is inputted in the correct sequnce. The reason for that is the way stack works.
    // 1 2 3  would be pushed in stack as 1 is the first element, 2 is the second and 3 is the third.
    //when we would print it, it would show 3 2 1 because the stack saved it as first in.
    printf("\t\t\t<- Current Linked List Content\n");
    print(&head);
}
reverse(&head);
printf("\t\t\t<- Reversed string is \n");
print(&head);
}
