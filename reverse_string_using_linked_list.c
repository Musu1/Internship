#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct node{
char a;
struct node* next;
}node;

void print(node* head){
while(head){
    printf("%s",head->a);
    head=head->next;
}
}

node* reverse(node* head){
node* current,*prev,*next,*temp;
prev=NULL;
temp=head;
while(current!= NULL){
    next=current->next; //saving the address of succeeding location
    current->next=prev; //Reversing the link
    prev=current;
    current=next;
        }
head=prev;
return(prev);
}

int main(){
char str[500];
int len,i;
printf("Enter a string");
scanf("%s",&str);
len=strlen(str);
// taking string in lined list
printf("%d",len);
for(i=0;i<len;i++){
        struct node* root=(struct node *)malloc(sizeof(struct node));
        root->a=str[i];
        root=root->next;
        print(root);
        //reversing the string
        root=reverse(root);
        //Printing the linked list
        print(root);
}
return 0;
}
