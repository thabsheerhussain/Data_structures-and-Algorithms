//Circular queue implementation 🇮🇳
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int q[MAX],front=-1,rear=-1;
void insert(int data)
{
	if(front==0 && rear==MAX-1)
	{
		printf("Overflow\n");
		return;
	}
	if(front==-1 && rear==-1)
		rear=front=0;
	else if(rear==MAX-1 && front!=0)
		rear=0;
	else
		rear++;
	q[rear]=data;
}
int delete()
{
	int val;
	if(front==-1)
	{
		printf("Underflow\n");
		return;
	}
	val=q[front];
	if(front==rear)
		front=rear=-1;
	else
	{
		if(front==MAX-1)
			front=0;
		else
			front++;
	}	
	return val;
}
void show()
{
	int i;
	if(front==-1 && rear==-1)
	{
		printf("Empty Queue");
		return;
	}
	if(front<=rear)
	{
		for(i=front;i<=rear;i++)
			printf("%d ",q[i]);
	}
	else
	{
		for(i=front;i<=MAX-1;i++)
			printf("%d ",q[i]);
		for(i=0;i<front;i++)
			printf("%d ",q[i]);     
	}
	printf("\n");
}
void main()
{
	int n,i,data;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		insert(data);
	}
	show();
	delete();
	show();
}
