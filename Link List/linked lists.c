//C program to implement linked lists

#include<stdio.h>
#incude<conio.h>
struct node{
       int data;
       struct node *node;
       struct node *next;
       };
struct node *start=NULL;
struct node *makenode(int d);
void insertfront( struct node *n);
void insertfront( struct node *n);
void insertsort( struct node *n);
struct node *search(int d);
struct node *delete(int d);
void traverse(struct node *p);
main()
{
	
}
struct node *makenode(int d)
{
   struct node *n;
   n=(struct node *)malloc(sizeof(struct node));
   n->data=d;
   n->next=NULL;
   return n;	
}
void insertfront( struct node *n) 
{
	if(start==NULL)
	{
       start=n;	
	}
	else
	{
		n->next=start;
		start=n;
	}
   
}
void insertback( struct node *n)
{
	int *p;
		if(start==NULL)
	{
       start=n;	
	}
	else
	{
		p=start;
    	while(p!=NULL)
    	{
		p=p->next;
	   }
	   	p->next=n;
	    n->next=NULL;	
	}
}
void insertsort( struct node *n)
{ 
     int *p,*q;
	if(start==NULL)
	{
		start=n;
	}
	p=start;
	while((p!=NULL) && (p->data < n-data))
	{
		q=p;
		p=p->next;
	}
   q->next=n;
   n->next=p;
}
struct node *search(int d)
{
	int *p,*q;
	p=start;
	while(p!=NULL)
	{
		if(p->data==d)
		{
			return p;
			// write print p->data after search
		}
		else
		{
		   q=p;
		   p=p->next;	
		}
	
	}
	printf("The searched no. is not found");
}
struct node *delete(int d)
{
	int d;
	int *p,*q;
	p=start;
	if(p->data==d)
	{
		start=p->next;
		free(p);
		break;
	}
	else
	{
	 while(p!=NULL)
	 {
	 	if(p->data==d)
	 	{
	 		q->next=p->next;
	 		free(p);
	 		break;
		 }
		 else
		 {
		 	q=p;
		 	p=p->next;
		 }
		 
		 printf("The number you need to delete is not found");
	
	 }	
	}
}
void traverse(struct node *p)
{
	p=start;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	getch();
}

