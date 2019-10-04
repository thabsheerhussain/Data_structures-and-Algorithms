//Insertion sort
#include<stdio.h>
#include<stdlib.h>
void insort(int a[],int n)
{
	int i,j,t;
	for(i=1;i<n;i++)
	{
		t=a[i];
		j=i-1;
		while(j>=0 && a[j]>t)
		{
			a[j+1]=a[j];
			j--;	
		}
		a[j+1]=t;
	}
}
void main()
{
	int a[100],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	insort(a,n);
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n");
}
