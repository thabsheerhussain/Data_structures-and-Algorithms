#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int partition(int a[],int beg,int end)
{
	int left,right,loc,f=0,t;
	loc=left=beg;
	right=end;
	while(f!=1)
	{
		while(a[right]>=a[loc] && loc!=right)
		{
			right--;
		}
		if(loc==right)
			f=1;
		else if(a[loc]>a[right])
		{
			t=a[loc];
			a[loc]=a[right];
			a[right]=t;
			loc=right;
		}
		if(f!=1)
		{
			while(a[left]<=a[loc] && loc!=left)
		{
			left++;
		}
		if(loc==left)
			f=1;
		else if(a[loc]<a[left])
		{
			t=a[loc];
			a[loc]=a[left];
			a[left]=t;
			loc=left;
		}	
		}
	}
	return loc;
}
void quick_sort(int a[],int beg,int end)
{
	int loc;
	if(beg<end)
	{
		loc=partition(a,beg,end);
		quick_sort(a,beg,loc-1);
		quick_sort(a,loc+1,end);
	}
}
void main()
{
	int n,i,a[MAX];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quick_sort(a,0,n-1);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
