//Linked List implementation 
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void main()
{
	struct node
		{
			int num;
			struct node *ptr;
		};
	typedef struct node NODE;

	NODE *head,*first,*temp=0;
	int count=0;
	int choice=1;
	first=0;
	while(choice)
	{
		head=(NODE *)malloc(sizeof(NODE));
		printf("Enter the data item\n");
		scanf("%d",&head->num);				
		if (first!=0)
		{
			temp->ptr=head;
			temp=head;
		}
		else
		{
			first=temp=head;		
		}
	fflush(stdin);
	printf("Do you wish to continue?(1/0)\n");
	scanf("%d",&choice);
	}
	temp->ptr=0;
	temp=first;
	printf("Status of linked list:\n");
	while(temp!=0)
		{
			printf("%d=>",temp->num);
			count++;
			temp=temp->ptr;
		}
	printf("NULL\n");
	printf("No of Nodes = %d",count);
}
