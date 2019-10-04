//Priority queue using linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	int pri;
	struct node *next;
};
struct node *head=NULL;
void insert(int data,int pri)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	struct node *p;
	temp->data=data;
	temp->pri=pri;
	temp->next=NULL;
	if(head==NULL || pri<head->pri)
	{
		temp->next=head;
		head=temp;
	}
	else
	{
		p=head;
		while(p->next!=NULL && p->next->pri<=pri)
		{
			p=p->next;
		}
		temp->next=p->next;
		p->next=temp;
	}
}
void delete()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("Underflow\n");
		return;
	}
	temp=head;
	head=head->next;
	free(temp);
}
void show()
{
	if(head==NULL)
	{
		printf("\nEmpty\n");
		return;
	}
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d-[priority %d]\n",temp->data,temp->pri);
		temp=temp->next;
	}
}
void main()
{
	int n,i,data,pri;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&data,&pri);
		insert(data,pri);
	}
	show();
	delete();
	printf("-------------------------------------\n");
	show();
}

