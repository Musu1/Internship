#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void rotate(struct Node **head_ref, int k)
{
     if (k == 0)
       return;
    struct Node* current = *head_ref;
    int count = 1;
    while (count < k && current != NULL)
    {
        current = current->next;
        count++;
    }
    if (current == NULL)
        return;
    struct Node *kthNode = current;
    while (current->next != NULL)
        current = current->next;

    current->next = *head_ref;
    *head_ref = kthNode->next;
    kthNode->next = NULL;
}
void push (struct Node** head_ref, int new_data)
{
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
int main(void)
{
    struct Node* head = NULL;
    int n,p;
    printf("How many numbers you want to add in the list\n");
    scanf("%d",&n);
    for (int i = 1; i <n ; i++){
        printf("Enter the number you want to add\n");
        scanf("%d",&p);
        push(&head, p);}
    int k;
    printf("Given linked list \n");
    printList(head);
    printf("Enter the numbers by which you want to rotate\n");
    scanf("%d",k);
    rotate(&head, k);
    printf("\nRotated Linked list \n");
    printList(head);
    return (0);
}
