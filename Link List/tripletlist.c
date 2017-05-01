// C/C++ program to find a triplet from three linked lists with sum equal to a given number
#include<stdio.h>
#include<stdlib.h>
 

struct node
{
    int data;
    struct node* next;
};
 

void push (struct node** head_ref, int new_data)
{

    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    new_node->data = new_data;
 

    new_node->next = (*head_ref);
 

    (*head_ref) = new_node;
}
 

bool isSumSorted(struct node *headA, struct node *headB, 
                 struct node *headC, int givenNumber)
{
    struct node *a = headA;
 

    while (a != NULL)
    {
        struct node *b = headB;
        struct node *c = headC;
 

        while (b != NULL && c != NULL)
        {

            int sum = a->data + b->data + c->data;
            if (sum == givenNumber)
            {
               printf ("Triplet Found: %d %d %d ", a->data,
                                         b->data, c->data);
               return true;
            }

            else if (sum < givenNumber)
                b = b->next;
            else 
                c = c->next;
        }
        a = a->next; 
    }
 
    printf ("No such triplet");
    return false;
}
 

int main()
{

    struct node* headA = NULL;
    struct node* headB = NULL;
    struct node* headC = NULL;
 

    push (&headA, 20);
    push (&headA, 4);
    push (&headA, 15);
    push (&headA, 10);
 
    
    push (&headB, 10);
    push (&headB, 9);
    push (&headB, 4);
    push (&headB, 2);
 
    push (&headC, 1);
    push (&headC, 2);
    push (&headC, 4);
    push (&headC, 8);
 
    int givenNumber = 25;
 
    isSumSorted (headA, headB, headC, givenNumber);
 
    return 0;
}