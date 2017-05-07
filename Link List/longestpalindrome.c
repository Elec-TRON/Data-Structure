// C++ program to find longest palindrome
#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    struct Node* next;
};
 int countCommon(Node *a, Node *b)
{
    int count = 0;
    for (; a && b; a = a->next, b = b->next)
        if (a->data == b->data)
            ++count;
        else
            break;
 
    return count;
}
 int maxPalindrome(Node *head)
{
    int result = 0;
    Node *prev = NULL, *curr = head;
 

    while (curr)
    {

        Node *next = curr->next;
        curr->next = prev;
 

        result = max(result,
                     2*countCommon(prev, next)+1);

        result = max(result,
                     2*countCommon(curr, next));

        prev = curr;
        curr = next;
    }
    return result;
}
 

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 
int main()
{

    Node *head = newNode(2);
    head->next = newNode(4);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(2);
    head->next->next->next->next->next = newNode(15);
 
    cout << maxPalindrome(head) << endl;
    return 0;
}