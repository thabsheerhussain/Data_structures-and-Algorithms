// Circular Linked List-Finding and Deleting Maximum Element 
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head,*last;
struct node *newnode()
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	return temp;
}
void insert(int data)
{
	struct node *temp=newnode();
	temp->data=data;
	temp->next=NULL;
	if(head==NULL)
	{
		head = last = temp;
	}
	else
	{
		last->next=temp;
		last=temp;
	}
	last->next=head;
}
void show()
{
	struct node *temp;
	temp=head;
	while(temp!=last)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("%d",temp->data);
}
struct node * max()
{
	struct node*temp=head->next;
	struct node *m=head;
	while(temp!=last)
	{
		if(temp->data>m->data)
		{
			m=temp;
		}
		temp=temp->next;
	}
	if(last->data>m->data)
		m=last;
		printf("max= %d",m->data);
	return m;
}
void deletemax()
{
	struct node *m,*prev;
	m=max();
	struct node *temp=head;
	struct node *n;
	while(temp!=m)
	{
		prev=temp;
		temp=temp->next;
	}
	if(m==head)
	{
		n=head;
		head=head->next;
		last->next=head;
		free(n);
	}
	if(m==last)
		last=prev;
	prev->next=m->next;
	
	
	free(m);
}
void delete()
{
	struct node *temp;
	temp=head;
	head=head->next;
	last->next=head;
	free(temp);
}
void main()
{
	int n,i,t;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		insert(t);
	}
	show();
	printf("\n");
	deletemax();
	printf("\n");
	show();
}
