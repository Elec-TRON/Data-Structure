//C program to implement bubble sort

#include<stdio.h>
#include<conio.h>
main()
{
 	int a[20]={9,8,7,6,5,4,3,2,1};
 	int i,changedone=1,n=9,t;
 	printf("the unsorted list will be");
 	for(i=0;i<9;i++)
	{
       printf("%d ",a[i]);
    }
 	do{
 				changedone=0;
                 for(i=0;i<n-1;i++)
 		  {
 			if(a[i]>a[i+1])
 			{
 					t=a[i];
				    a[i]=a[i+1];
				     a[i+1]=t;
 					changedone=1;
			 }
		  
		 }
 	
	 }while(changedone==1);
	 printf("the sorted list is ");
	 	for(i=0;i<9;i++)
	{
       printf("%d ",a[i]);
    }
getch();

}
