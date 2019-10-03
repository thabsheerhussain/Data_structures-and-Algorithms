#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct node
{
	int data;
	struct node *next;
};
struct array
{
	struct node *head;
	int key;
};
struct array a[MAX];
void init()
{
	for(int i=0;i<MAX;i++)
	{
		a[i].key=-1;
		a[i].head=NULL;
	}
}
int hashcode(int key)
{
	return key%MAX;
}
void insert(int data)
{
	int index=hashcode(data);
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	if(a[index].head==NULL)
	{
		a[index].head=temp;
		a[index].key=index;
	}
	else
	{
		struct node *ptr=a[index].head;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=temp;
		a[index].key=index;
	}
}
void search(int data)
{
	int index=hashcode(data);
	if(a[index].head==NULL)
	{
		printf("Data not found\n");
		return;
	}
	struct node *temp=a[index].head;
	while(temp!=NULL)
	{
		if(temp->data==data)
		{
			printf("Data Found\n");
			break;
		}
		temp=temp->next;
	}
}
void print()
{
	struct node *temp;
	int i;
	for(i=0;i<MAX;i++)
	{
		if(a[i].head!=NULL)
		{
			temp=a[i].head;
			while(temp!=NULL)
			{
				printf("%d ",temp->data);
				temp=temp->next;
			}
			printf("\n");
		}
	}
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
	print();
	printf("Enter data to be searched\n");
	scanf("%d",&data);
	search(data);
}
