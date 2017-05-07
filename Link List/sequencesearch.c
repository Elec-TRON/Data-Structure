//C program to implement sequential search

#include<stdio.h>
#include<conio.h>
main()
{
 int a[50]={1,2,3,4,5,6,7,8,9,10,12,13,45};
 int i=0,n,x=0,y;
 printf("enter the no. to find");
 scanf("%d",&n);
 for(i=0;a[i]!='\0';i++)
 {
    if(n==a[i])
    {
       x++;
       y=i;
       }
       
}
  if(x==0)
           {
                     printf("the no. %d is not found in the array",n);
                     }
                     else
                     {
                           printf("the no. %d is found in the array",n);
                           }
           getch();
           }

