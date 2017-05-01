// C program to find union and intersection of two unsorted 
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
 

void push(struct node** head_ref, int new_data);
 

bool isPresent(struct node *head, int data);
 

struct node *getUnion(struct node *head1, struct node *head2)
{
    struct node *result = NULL;
    struct node *t1 = head1, *t2 = head2;
 

    while (t1 != NULL)
    {
        push(&result, t1->data);
        t1 = t1->next;
    }

    while (t2 != NULL)
    {
        if (!isPresent(result, t2->data))
            push(&result, t2->data);
        t2 = t2->next;
    }
 
    return result;
}
 

struct node *getIntersection(struct node *head1, 
                              struct node *head2)
{
    struct node *result = NULL;
    struct node *t1 = head1;
 
 
    while (t1 != NULL)
    {
        if (isPresent(head2, t1->data))
            push (&result, t1->data);
        t1 = t1->next;
    }
 
    return result;
}
 

void push (struct node** head_ref, int new_data)
{

    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
   
    new_node->data = new_data;
 

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}
 

void printList (struct node *node)
{
    while (node != NULL)
    {
        printf ("%d ", node->data);
        node = node->next;
    }
}

bool isPresent (struct node *head, int data)
{
    struct node *t = head;
    while (t != NULL)
    {
        if (t->data == data)
            return 1;
        t = t->next;
    }
    return 0;
}
 

int main()
{

    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* intersecn = NULL;
    struct node* unin = NULL;
 
    
    push (&head1, 20);
    push (&head1, 4);
    push (&head1, 15);
    push (&head1, 10);

    push (&head2, 10);
    push (&head2, 2);
    push (&head2, 4);
    push (&head2, 8);
 
    intersecn = getIntersection (head1, head2);
    unin = getUnion (head1, head2);
 
    printf ("\n First list is \n");
    printList (head1);
 
    printf ("\n Second list is \n");
    printList (head2);
 
    printf ("\n Intersection list is \n");
    printList (intersecn);
 
    printf ("\n Union list is \n");
    printList (unin);
 
    return 0;
}