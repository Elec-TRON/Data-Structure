// A recursive program to add two linked lists
 
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node* next;
};
 
typedef struct node node;
 

void push(struct node** head_ref, int new_data)
{

    struct node* new_node = (struct node*) malloc(sizeof(struct node));
 

    new_node->data  = new_data;
 
    
    new_node->next = (*head_ref);

    (*head_ref)    = new_node;
}
 

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
    printf("\n");
}
 

void swapPointer( node** a, node** b )
{
    node* t = *a;
    *a = *b;
    *b = t;
}
 
int getSize(struct node *node)
{
    int size = 0;
    while (node != NULL)
    {
        node = node->next;
        size++;
    }
    return size;
}
 

node* addSameSize(node* head1, node* head2, int* carry)
{

    if (head1 == NULL)
        return NULL;
 
    int sum;
 
    
    node* result = (node *)malloc(sizeof(node));
 
    
    result->next = addSameSize(head1->next, head2->next, carry);

    sum = head1->data + head2->data + *carry;
    *carry = sum / 10;
    sum = sum % 10;
 
    
    result->data = sum;
 
    return result;
}
 

void addCarryToRemaining(node* head1, node* cur, int* carry, node** result)
{
    int sum;
 
    if (head1 != cur)
    {
        addCarryToRemaining(head1->next, cur, carry, result);
 
        sum = head1->data + *carry;
        *carry = sum/10;
        sum %= 10;
 
        push(result, sum);
    }
}
 

void addList(node* head1, node* head2, node** result)
{
    node *cur;
 

    if (head1 == NULL)
    {
        *result = head2;
        return;
    }
 
    
    else if (head2 == NULL)
    {
        *result = head1;
        return;
    }
 
    int size1 = getSize(head1);
    int size2 = getSize(head2) ;
 
    int carry = 0;
 

    if (size1 == size2)
        *result = addSameSize(head1, head2, &carry);
 
    else
    {
        int diff = abs(size1 - size2);

        if (size1 < size2)
            swapPointer(&head1, &head2);
 
       
        for (cur = head1; diff--; cur = cur->next);
 

        *result = addSameSize(cur, head2, &carry);
 
        
        addCarryToRemaining(head1, cur, &carry, result);
    }

    if (carry)
        push(result, carry);
}

int main()
{
    node *head1 = NULL, *head2 = NULL, *result = NULL;
 
    int arr1[] = {9, 9, 9};
    int arr2[] = {1, 8};
 
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
 

    int i;
    for (i = size1-1; i >= 0; --i)
        push(&head1, arr1[i]);
 
    
    for (i = size2-1; i >= 0; --i)
        push(&head2, arr2[i]);
 
    addList(head1, head2, &result);
 
    printList(result);
 
    return 0;
}