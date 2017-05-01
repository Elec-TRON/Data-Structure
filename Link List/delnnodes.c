// C program to delete n nodes

#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *next;
};
 
void deleteNode(struct node *head, struct node *n)
{

    if(head == n)
    {
        if(head->next == NULL)
        {
            printf("There is only one node. The list can't be made empty ");
            return;
        }
 
        head->data = head->next->data;
 

        n = head->next;
 
        head->next = head->next->next;
 
        free(n);
 
        return;
    }
 
 
    struct node *prev = head;
    while(prev->next != NULL && prev->next != n)
        prev = prev->next;
 
    if(prev->next == NULL)
    {
        printf("\n Given node is not present in Linked List");
        return;
    }
 
    prev->next = prev->next->next;

    free(n);
 
    return; 
}
 
void push(struct node **head_ref, int new_data)
{
    struct node *new_node =
        (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
 
void printList(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
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
 
    printf("Given Linked List: ");
    printList(head);

    printf("\nDeleting node %d: ", head->next->next->data);
    deleteNode(head, head->next->next);
 
    printf("\nModified Linked List: ");
    printList(head);

    printf("\nDeleting first node ");
    deleteNode(head, head);
 
    printf("\nModified Linked List: ");
    printList(head);
 
    getchar();
    return 0;
}