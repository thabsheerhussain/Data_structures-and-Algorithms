#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void merge(int a[],int beg,int mid,int end)
{
	int temp[MAX],i=beg,j=mid+1,index=beg,k;
	while((i<=mid) && (j<=end))
	{
		if(a[i]<a[j])
		{
			temp[index]=a[i];
			i++;
			index++;
		}
		else
		{
			temp[index]=a[j];
			j++;
			index++;
		}
	}
	
	while(i<=mid)
	{
		temp[index]=a[i];
		i++;
		index++;
	}
	
	
	while(j<=end)
	{
		temp[index]=a[j];
		j++;
		index++;
	}
	
	for(k=beg;k<index;k++)
	{
		a[k]=temp[k];
	}
}
void merge_sort(int a[],int beg,int end)
{
	int mid;
	if(beg<end)
	{
		mid=(beg+end)/2;
		merge_sort(a,beg,mid);
		merge_sort(a,mid+1,end);
		merge(a,beg,mid,end);
	}
}
void main()
{
	int a[MAX],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	merge_sort(a,0,n-1);
	printf("Sorted Array is:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
