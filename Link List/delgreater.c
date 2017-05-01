// C program to delete nodes which have a greater value on right
#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node *next;
};
 

void reverseList(struct node **headref);
void _delLesserNodes(struct node *head);

void delLesserNodes(struct node **head_ref)
{
  
    reverseList(head_ref);
 

    _delLesserNodes(*head_ref);
 

    reverseList(head_ref);
}
 

void _delLesserNodes(struct node *head)
{
     struct node *current = head;
 

     struct node *maxnode = head;
     struct node *temp;
 
     while (current != NULL && current->next != NULL)
     {

         if(current->next->data < maxnode->data)
         {
             temp = current->next;
             current->next = temp->next;
             free(temp);
         }
 

         else
         {
             current = current->next;
             maxnode = current;
         }
     }
}
 

void push(struct node **head_ref, int new_data)
{
     struct node *new_node =
              (struct node *)malloc(sizeof(struct node));
     new_node->data = new_data;
     new_node->next = *head_ref;
     *head_ref = new_node;
}
 

void reverseList(struct node **headref)
{
     struct node *current = *headref;
     struct node *prev = NULL;
     struct node *next;
     while (current != NULL)
     {
          next = current->next;
          current->next = prev;
          prev = current;
          current = next;
     }
     *headref = prev;
}
 

void printList(struct node *head)
{
     while (head != NULL)
     {
        printf("%d ", head->data);
        head=head->next;
     }
     printf("\n");
}

int main()
{
    struct node *head = NULL;
 
    push(&head,3);
    push(&head,2);
    push(&head,6);
    push(&head,5);
    push(&head,11);
    push(&head,10);
    push(&head,15);
    push(&head,12);
 
    printf("Given Linked List \n");
    printList(head);
 
    delLesserNodes(&head);
 
    printf("Modified Linked List \n");
    printList(head);
 
     return 0;
}