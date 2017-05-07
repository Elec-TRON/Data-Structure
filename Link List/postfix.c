//C program to convert postfix to value

#include<stdio.h>
#include<conio.h>
#include"stackslibrary.c"
main()
{
    char expr[100];
    int i=0,b=0,a=0;
    printf("Enter the expression");
    gets(expr);
     for(i=0;expr[i]!='\0';i++)
     {
           if(isdigit(expr[i]))
           {
              push(expr[i]-'0');
           }
          else
          {
              b=pop();
              a=pop();
          }
           if(expr[i]=='+')
           {
               push(a+b);
           }
           if(expr[i]=='*')
           {
                push(a*b);
           }
           if(expr[i]=='-')
           {
                 push(a-b);
           }
           if(expr[i]=='/')
           {
                  push(a/b);
           }                                    
          
     }
     a=pop();
     printf("the value of expression is %d",a);
     getch();
}           
                                                                
