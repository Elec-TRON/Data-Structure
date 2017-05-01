//C program to convert decimal number tobinary via stacks

#include<stdio.h>
#include<conio.h>
#include"stackslibrary.c"
main()
{
    int n,r,x;
    printf("Enter the decimal\n");
    scanf("%d",&n);
    while(n>0)
    {
        r=n%2;
        push(r);
        n=n/2;

    }
    while(!isempty())
    {
       x=pop();
       printf("%d",x);
    }
}
