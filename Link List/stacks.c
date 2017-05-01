//C program to test stacks

#include<stdio.h>
#include<conio.h>
#define makstackdata 200
int stackdata [makstackdata];
int top=-1;
void push(int d)
{
  top++;
  stackdata[top]=d;

}

int pop()
{
  int d;
  d=stackdata[top];
  top--;
  return d;
}

isempty()
{
   if(top==-1)
   {
       return 1;
    }
    else
    {
       return 0;
    }
}

isfull()
{
   if(top==makstackdata-1)
   {
      return 1;
   }
   else
   {
      return 0;

   }
}

int initialize()
{
    top=0;
}
int peek()
{
    int d;
    d=stackdata[top];
    return d;
}

int main()
{
            int x=0;

  push(10);
  push(20);
  push(30);
  push(40);
  push(50);
  x=pop();
  push(60);
  x=pop();
  printf("%d",x);
}
