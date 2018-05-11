#include<stdio.h>
#include<stdlib.h>

typedef struct Node

{
    int info;
    struct Node *next;
}node;

node *front=NULL,*rear=NULL,*temp;
int count=1;
void create();
void display();
void rotating();

int main()
{
    int chc;
    do
    {
     printf("\nMenu\n\t 1 to create the element : ");
    printf("\n\t 2 to display the queue : ");
    printf("\n\t 3 to rotate by some number");
    printf("\n\t 4 to exit from main : ");
    printf("\nEnter your choice : ");
    scanf("%d",&chc);

        switch(chc)
        {
            case 1:
             create();
            break;

             case 2:
             display();
             break;

             case 3:
                rotating();
                break;

            case 4:
             return 1;

            default:
                 printf("\nInvalid choice :");
         }
    }while(1);

    return 0;
}

void create()
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\nEnter the node value : ");
    scanf("%d",&newnode->info);
    newnode->next=NULL;
    if(rear==NULL)
    front=rear=newnode;
    else
    {
        rear->next=newnode;
        rear=newnode;
    }

    rear->next=front;
}


void display()
{
    temp=front;
    if(front==NULL)
        printf("\nEmpty");
    else
    {
        printf("\n");
        for(;temp!=rear;temp=temp->next){
            printf("\n%d address=%u next=%u\t",temp->info,temp,temp->next);
            count=count+1;}
            printf("\n%d address=%u next=%u\t",temp->info,temp,temp->next);

    }
}

void rotating(){
    printf("\nEnter the length of the list\n");
    int d;
    scanf("%d",&d);
printf("\nHow much you want to rotate\n");
int k,i,j,t1,t2;
scanf("%d",&k);
//printf("\n%d address=%u next=%u\t",temp->info,temp,temp->next);
temp=front;
//printf("\n%d address=%u next=%u\t",temp->info,temp,temp->next);
t1=front->info;
for(i=1;i<=k;i++){
       // printf("\n%d address=%u next=%u\t",temp->info,temp,temp->next);
       //printf("%d",count);
    do{
        //printf("\n%d address=%u next=%u\t",temp->info,temp,temp->next);
        temp=temp->next;
        t2=temp->info;
        temp->info=t1;
        t1=t2;
        }while(temp!=front);
        //printf("\n%d address=%u next=%u\t",temp->info,temp,temp->next);
}
display();
}
