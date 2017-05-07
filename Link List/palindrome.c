// C Program to check if a linked list is palindrome 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
 
struct node
{
    char data;
    struct node* next;
};
 
void reverse(struct node**);
bool compareLists(struct node*, struct node *);

bool isPalindrome(struct node *head)
{
    struct node *slow_ptr = head, *fast_ptr = head;
    struct node *second_half, *prev_of_slow_ptr = head;
    struct node *midnode = NULL;  
    bool res = true; 
 
    if (head!=NULL && head->next!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            prev_of_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
 

        if (fast_ptr != NULL)
        {
            midnode = slow_ptr;
            slow_ptr = slow_ptr->next;
        }

        second_half = slow_ptr;
        prev_of_slow_ptr->next = NULL; 
        reverse(&second_half); 
        res = compareLists(head, second_half);
 
         reverse(&second_half); 

         if (midnode != NULL) 
         {
            prev_of_slow_ptr->next = midnode;
            midnode->next = second_half;
         }
         else  prev_of_slow_ptr->next = second_half;
    }
    return res;
}

void reverse(struct node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
 

bool compareLists(struct node* head1, struct node *head2)
{
    struct node* temp1 = head1;
    struct node* temp2 = head2;
 
    while (temp1 && temp2)
    {
        if (temp1->data == temp2->data)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else return 0;
    }
 
    if (temp1 == NULL && temp2 == NULL)
        return 1;

    return 0;
}
 
void push(struct node** head_ref, char new_data)
{

    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));

    new_node->data  = new_data;
 
    new_node->next = (*head_ref);

    (*head_ref)    = new_node;
}
 
void printList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%c->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node* head = NULL;
    char str[] = "abacaba";
    int i;
 
    for (i = 0; str[i] != '\0'; i++)
    {
       push(&head, str[i]);
       printList(head);
       isPalindrome(head)? printf("Is Palindrome\n\n"):
                           printf("Not Palindrome\n\n");
    }
 
    return 0;
}
