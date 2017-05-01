// C/C++ program to segregate even and odd nodes in a
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
 
void segregateEvenOdd(struct node **head_ref)
{
    struct node *end = *head_ref;
    struct node *prev = NULL;
    struct node *curr = *head_ref;

    while (end->next != NULL)
        end = end->next;
 
    struct node *new_end = end;
 

    while (curr->data %2 != 0 && curr != end)
    {
        new_end->next = curr;
        curr = curr->next;
        new_end->next->next = NULL;
        new_end = new_end->next;
    }
 

    if (curr->data%2 == 0)
    {

        *head_ref = curr;
 

        while (curr != end)
        {
            if ( (curr->data)%2 == 0 )
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {

                prev->next = curr->next;

                curr->next = NULL;
 

                new_end->next = curr;

                new_end = curr;
 

                curr = prev->next;
            }
        }
    }
 
    else prev = curr;
 

    if (new_end!=end && (end->data)%2 != 0)
    {
        prev->next = end->next;
        end->next = NULL;
        new_end->next = end;
    }
    return;
}
 
void push(struct node** head_ref, int new_data)
{

    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    new_node->data  = new_data;
 

    new_node->next = (*head_ref);

    (*head_ref)    = new_node;
}
 
void printList(struct node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 

int main()
{

    struct node* head = NULL;

 
    push(&head, 11);
    push(&head, 10);
    push(&head, 8);
    push(&head, 6);
    push(&head, 4);
    push(&head, 2);
    push(&head, 0);
 
    printf("\nOriginal Linked list \n");
    printList(head);
 
    segregateEvenOdd(&head);
 
    printf("\nModified Linked list \n");
    printList(head);
 
    return 0;
}