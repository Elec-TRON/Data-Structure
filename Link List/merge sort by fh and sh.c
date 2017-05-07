//C program to implement merge sort

#include<stdio.h>
#include<conio.h>
main()
{
	int a[20]={9,8,7,6,5,4,3,2,1};
	int asize,i;
	asize=9;
	printf("the un sorted list will be:");
	for(i=0;i<9;i++)
	{
       printf("%d",a[i]);
    }
	mergesort(a[20],asize);
	printf("The sorted algorith will be");
	for(i=0;i<9;i++)
	{
       printf("%d",a[i]);
    }

}




int mergesort(int list[], int size)
{
	if(size>1)
	{
		int fh[10],fhsize,sh[10],shsize;
		int mid,i;
		mid=size/2;
		for(i=0;i<mid;i++)
		{
			fh[i]=list[i];
		
		}
		fhsize=mid-1;
		for(i=0;i<size-mid;i++)
		{
			sh[i]=list[i];
		}
		shsize=mid+1;
		mergrsort(fh[10],fhsize);
		mergrsort(sh[10],shsize);
		merge(list,fh,fhsize,sh,shsize);
	}
}





int merge(int list[],int l1[],int l1size,int l2[],int l2size)
{
	int list[],l1[],l2[],l1size,l2size;
	int i=0,j=0,k=0;
	for(i=0;i<l1;i++)
   	{
   		for(j=0;j<l2size;j++)
   		{
   			if(l1[i]<l2[j])
   			{
   				list[k]=l1[i];
   				i++;
   				k++;
			}
			else
			{
				list[k]=l2[j];
				j++;
				k++;
			}
			if(i==l1size)
			{
				while(j<l2size)
				{
					list[k]=l2[j];
					k++;
					j++;
				}
			}
			if(i==l2size)
			{
			   		while(i<l2size)
				{
					c[k]=a[i];
					k++;
					i++;
				}
			}
		}
	}
}
