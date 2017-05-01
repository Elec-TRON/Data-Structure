//C program for stacks library

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
