//Selection Sort
#include<stdio.h>
#include<stdlib.h>
void selsort(int a[],int n)
{
	int i,j,min,t;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min=j;
		}
		t=a[i];
		a[i]=a[min];
		a[min]=t;
	}
}
void main()
{
	int a[100],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	selsort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
