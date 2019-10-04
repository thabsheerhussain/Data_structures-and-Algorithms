//Most basic hashing 
#include<stdio.h>
#include<stdlib.h>
int hash[128];
int x;

int hashing(int key)
{
	int n;
	n=key%128;
	return n;	
}
int max(int n);
void main()
{
	for(x=0;x<=127;x++)
		hash[x]=0;

	int a[100];
	int n,i,p;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		p=hashing(a[i]);
		hash[p]++;
	}
	int ma=max(n);
	printf("%d ",a[ma]);
}
int max(int n)
{
	int i;
	int mx=0;
	for(i=0;i<n;i++)
	{
		if(hash[i]>hash[mx])
		mx=i;
	}
	return max;
}
