#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void insert(int a[],int *hsize,int data)
{
	int pos,par,t;
	if(*hsize==MAX-1)
		return;
	(*hsize)++;
	a[*hsize]=data;
	pos=(*hsize);
	while(pos>1)
	{
		par=pos/2;
		if(a[par]<=a[pos])
			return;
		else
		{
			t=a[par];
			a[par]=a[pos];
			a[pos]=t;
			pos=par;
		}
	}
}
int delete(int a[],int *hsize)
{
	int val;
	if((*hsize)==0)
		return 0;
	val=a[1];
	a[1]=a[*hsize];
	(*hsize)--;
	int root,left,right,t;
	root=1;
	left=2;
	right=3;
	while(left<=(*hsize))
	{
		if(a[root]<=a[left] && a[root]<=a[right])
		{
			return val;
		}
		else
		{
			if(a[left]<a[right])
			{
				t=a[root];
				a[root]=a[left];
				a[left]=t;
				root=left;
			}
			else
			{
				t=a[root];
				a[root]=a[right];
				a[right]=t;
				root=right;
			}
		}
		left=2*root;
		right=left+1;
	}
	return val;
}
void print(int a[],int hsize)
{
	int i;
	for(i=1;i<=hsize;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void main()
{
	int a[MAX],heap[MAX],n,i,hsize=0;
	a[0]=99999;
	heap[0]=99999;
	int val;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		insert(heap,&hsize,a[i]);
	}
	print(heap,hsize);
	for(i=1;i<=n;i++)
	{
		val=delete(heap,&hsize);
		a[i]=val;
	}
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
