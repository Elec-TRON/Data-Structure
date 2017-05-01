/* C Program to remove duplicates from a sorted linked list */
#include<stdio.h>
#include<stdlib.h>
 

struct node
{
    int data;
    struct node* next;
};
 

void removeDuplicates(struct node* head)
{
    struct node* current = head;
 
    
    struct node* next_next; 
   

    if (current == NULL) 
       return; 
 

    while (current->next != NULL) 
    {

       if (current->data == current->next->data) 
       {
            
           next_next = current->next->next;
           free(current->next);
           current->next = next_next;  
       }
       else 
       {
          current = current->next; 
       }
    }
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

    push(&head, 20);
    push(&head, 13);
    push(&head, 13);  
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);                                    
 
    printf("\n Linked list before duplicate removal  ");
    printList(head); 
 

    removeDuplicates(head); 
 
    printf("\n Linked list after duplicate removal ");         
    printList(head);            
   
    return 0;
}