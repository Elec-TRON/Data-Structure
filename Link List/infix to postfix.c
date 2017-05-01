//C program to convert infix to postfix

#include<stdio.h>
#include<conio.h>
#include"stackslibrary.c"
int opval(char d)
{
	if(d=='-')
	{
		return 1;
	}
		if(d=='+')
	{
		return 2;
	}
		if(d=='*')
	{
		return 3;
	}
		if(d=='/')
	{
		return 4;
	}
}
main()
{
	char expr[100];
	char output[100];
	int i=0, j=0;
	printf("Enter the infix expression");
	gets(expr);
	for(i=0;expr[i]!='\0';i++)
	{
		if(isdigit(expr[i]))
		{
			output[j]=expr[i];
			j++;
		}
		else
		{
			if(opval(expr[i])>opval(peek()))
			{
				push(expr[i]);
			}
			else
			{
				while(opval(expr[i])<opval(peek()))
				{
					output[j]=pop();
					j++;
				}
			}
		}
	}
	while(!isempty())
	{
		output[j]=pop();
	}
	puts(output);
}
