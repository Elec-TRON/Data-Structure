// C Program to delete all occurrences of a given key in linked list
#include <stdio.h>
#include <stdlib.h>
 

struct node
{
    int data;
    struct node *next;
};
 
void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
 

void deleteKey(struct node **head_ref, int key)
{

    struct node* temp = *head_ref, *prev;
 

    while (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;   
        free(temp);               
        temp = *head_ref;      
    }
 
    while (temp != NULL)
    {

        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;

        prev->next = temp->next;
 
        free(temp); 
 

        temp = prev->next;
    }
}

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}
 
int main()
{

    struct node* head = NULL;
 
    push(&head, 7);
    push(&head, 2);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);
    push(&head, 1);
    push(&head, 2);
    push(&head, 2);
 
    int key = 2;
 
    puts("Created Linked List: ");
    printList(head);
 
    deleteKey(&head, key);
    puts("\nLinked List after Deletion of 1: ");
 
    printList(head);
    return 0;
}