//C program to reveres at K the linked list

#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *ptr;
struct node *header;
struct node *temp;
int makenode(int num) 
{
	temp = (struct node *)malloc(sizeof(struct node));
	ptr = header;
	if(ptr->next == -999)
	{
		ptr->data = num;
		ptr->next = NULL;
	}
	else
	{
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		temp->data = num;
		ptr->next = temp;
		temp->next =NULL;	
	}
	return 0;
}
int display()
{
	ptr = header;
	printf("%d -> ", ptr->data);
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
		printf("%d -> ", ptr->data);
	}
	printf("NULL");
	return 0;
}
int reverseGroup(int val)
{
	int count = 0;
	int headval;
	struct node *prev, *curr, *nxt, *temp1;
	prev = (struct node *)malloc(sizeof(struct node));
	curr = (struct node *)malloc(sizeof(struct node));
	nxt = (struct node *)malloc(sizeof(struct node));
	curr = header;
	prev = NULL;
	nxt = NULL;
	while(curr !=NULL && count<val)
	{
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
		count++;
	}
	header = prev;
	return 0;
}
int main()
{
	int a;
	header = (struct node *) malloc(sizeof(struct node));
	header->data = -999;
	header->next = -999;
	makenode(1);
	makenode(2);
	makenode(3);
	makenode(4);
	makenode(5);
	makenode(6);
	makenode(7);
	makenode(8);
	makenode(9);
	display();
	printf("\n");
	printf("Enter a number to reverse in group\n");
	scanf("%d", &a);
	reverseGroup(a);
	display();
	return 0;
}