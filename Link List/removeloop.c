//C program to find loop in list

#include<stdio.h>
#include<stdlib.h>
 

struct node
{
    int data;
    struct node* next;
};
 
void removeLoop(struct node *, struct node *);
 

int detectAndRemoveLoop(struct node *list)
{
    struct node  *slow_p = list, *fast_p = list;
 
    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
 
         if (slow_p == fast_p)
        {
            removeLoop(slow_p, list);
 

            return 1;
        }
    }

    return 0;
}
 

void removeLoop(struct node *loop_node, struct node *head)
{
   struct node *ptr1;
   struct node *ptr2;
 

   ptr1 = head;
   while (1)
   {
      ptr2 = loop_node;
     while (ptr2->next != loop_node && ptr2->next != ptr1)
         ptr2 = ptr2->next;

     if (ptr2->next == ptr1)
        break;
 
     ptr1 = ptr1->next;
   }

   ptr2->next = NULL;
}
 
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}
 
struct node *newNode(int key)
{
    struct node *temp = new struct node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 
int main()
{
    struct node *head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    head->next->next->next->next->next = head->next->next;
 
    detectAndRemoveLoop(head);
 
    printf("Linked List after removing loop \n");
    printList(head);
    return 0;
}