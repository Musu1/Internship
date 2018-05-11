#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int data;
struct node* next;
}node;

void create(int a){
    node* temp,*end;
    temp=(node*)malloc(sizeof(node));
    temp->data=a;
    temp->next=NULL;
    if(end==NULL){
        end=temp;
        temp->next=end;}
    else{
        end->next=temp->next;
        end->next=temp;
        end=temp;
    }

    }

void display(){
    node* end;
    while(end){
    printf("%d",end->data);
    end=end->next;
}
}

int main(){
printf("Enter the number you want to add in the list");
int a;
scanf("%d",&a);
create(a);
display();
return 0;
}

