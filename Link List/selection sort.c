//C program to implement selection sort

#include<stdio.h>
#include<conio.h>
main()
{
	int a[20]={9,8,7,6,5,4,3,2,1};
	int i,j,t;
	printf("the un sorted list will be:");
	for(i=0;i<9;i++)
	{
       printf("%d ",a[i]);
    }
	for(i=0;i<9;i++)
	{
		for(j=i;j<9;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	printf("The sorted algorith will be");
		for(i=0;i<9;i++)
	{
       printf("%d ",a[i]);
    }
    getchar();
}

