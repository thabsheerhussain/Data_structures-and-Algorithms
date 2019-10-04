//Doubly Linked List simple implementation
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL;
struct node *last=NULL;
struct node *newnode()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	return temp;
}
void insert(int data)
{
	struct node *temp;
	temp=newnode();
	temp->data=data;
	temp->next=NULL;
	temp->prev=NULL;
	if(head==NULL)
		head=last=temp;
	else
	{
		last->next=temp;
		temp->prev=last;
		last=temp;
	}
}
void delete()
{
	struct node *temp=head;
	struct node *n=NULL;
	while(temp->next!=NULL)
	{
		n=temp;
		temp=temp->next;
	}
	n->next=NULL;
	temp->prev=NULL;
	last=n;
	free(temp);
}
void show()
{
	struct node *temp1=head;
	struct node *temp2=last;
	while(temp1!=NULL)
	{
		printf("%d ",temp1->data);
		temp1=temp1->next;
	}
	printf("\n");
	while(temp2!=NULL)
	{
		printf("%d ",temp2->data);
		temp2=temp2->prev;
	}
	printf("\n");
}
void main()
{
	int n,i,t;
	scanf("%d ",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		insert(t);
	}
	show();
	delete();
	show();
}
