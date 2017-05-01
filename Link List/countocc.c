// C/C++ program to count occurrences in a linked list
#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    int data;
    struct node* next;
};
 

void push(struct node** head_ref, int new_data)
{

    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
 

    new_node->data  = new_data;
 
    new_node->next = (*head_ref);

    (*head_ref)    = new_node;
}
 
int count(struct node* head, int search_for)
{
    struct node* current = head;
    int count = 0;
    while (current != NULL)
    {
        if (current->data == search_for)
           count++;
        current = current->next;
    }
    return count;
}
 

int main()
{

    struct node* head = NULL;
 

    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
 
    printf("count of 1 is %d", count(head, 1));
    return 0;
}