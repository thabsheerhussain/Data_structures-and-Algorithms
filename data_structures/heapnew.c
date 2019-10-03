#include<stdio.h>
#include<stdlib.h>
void insert(int a[],int *hsize,int data);
void del(int a[],int *hsize);
void print(int a[],int hsize);
void main()
{
	int n,i,t,hsize=0;
	int a[100];
	a[0]=99999;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		insert(a,&hsize,t);
	}
	print(a,hsize);
	del(a,&hsize);
	print(a,hsize);
}
void insert(int a[],int *hsize,int data)
{
	int par,t,pos;
	(*hsize)++;
	pos=(*hsize);
	a[*hsize]=data;
	while(pos>1)
	{
		par=pos/2;
		if(a[pos]<=a[par])
			return;
		else 
		{
			t=a[pos];
			a[pos]=a[par];
			a[par]=t;
			pos=par;	
		}
	}
}
void del(int a[],int *hsize)
{
	int root,left,right,t;
	a[1]=a[*hsize];	
	(*hsize)--;
	root=1;
	left=2;	
	right=3;
	
	while(left<=(*hsize))
	{
		if(a[root]>=a[left] && a[root]>=a[right])
			return;
		else if(a[left]>a[right])
			{
				t=a[left];
				a[left]=a[root];
				a[root]=t;
				root=left;
			}
		else
			{
				t=a[right];
				a[right]=a[root];
				a[root]=t;
				root=right;
			}
			left=2*root;
			right=left+1;
	}
	
}
void print(int a[],int hsize)
{
	int i;
	for(i=1;i<=hsize;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
