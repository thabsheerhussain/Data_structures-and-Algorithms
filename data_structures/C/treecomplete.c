//Complete Tree Oprations
#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *left,*right;
};
struct node *mirror(struct node *root)
{
	while(root!=NULL)
	{
		mirror(root->left);
		mirror(root->right);
		struct node *temp;
		temp=root->left;
		root->left=root->right;
		root->right=temp;
	}
	return root;
}
struct node *newnode(int data)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
struct node *insert(struct node *root,int data)
{
	if(root==NULL)
		return newnode(data);
	if(root->data<=data)
		root->right=insert(root->right,data);
	else
		root->left=insert(root->left,data);
	return root;
}
void PrintGivenLevel(struct node *root,int level);
void inorder(struct node *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
int height(struct node *root)
{
	if(root==NULL)
		return 0;
	else
	{
		int lheight=height(root->left);
		int rheight=height(root->right);
		if(lheight>rheight)
			return lheight+1;
		else
			return rheight+1;
	}
}
int totalnodes(struct node *root)
{
	if (root==NULL)
		return 0;
	else
		return totalnodes(root->left)+totalnodes(root->right)+1;
}
int internalnodes(struct node *root)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 0;
	else
		return internalnodes(root->left)+internalnodes(root->right)+1;
}
int externalnodes(struct node *root)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 1;
	else
		return externalnodes(root->left)+externalnodes(root->right);
}
struct node *minValueNode(struct node *root)
{
	struct node *temp=root;
	while(temp->left!=NULL)
		temp=temp->left;
	return temp;
}
struct node *maxValueNode(struct node *root)
{
	struct node *temp=root;
	while(temp->right!=NULL)
		temp=temp->right;
	return temp;
}

struct node *deletenode(struct node *root,int data)
{
	if(root==NULL)
		return root;
	if(data<root->data)
		root->left=deletenode(root->left,data);
	else if(data>root->data)
		root->right=deletenode(root->right,data);
	else
	{
		if(root->left==NULL)
		{
			struct node *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			struct node *temp=root->left;
			free(root);
			return temp;
		}
		struct node *temp=minValueNode(root->right);
		root->data=temp->data;
		root->right=deletenode(root->right,temp->data);
	}
	return root;
}
void LevelOrder(struct node *root)
{
	int h=height(root);
	int i;
	for(i=1;i<=h;i++)
	{
		PrintGivenLevel(root,i);
	}
}
void PrintGivenLevel(struct node *root,int level)
{
	if(root==NULL)
		return;
	if(level==1)
		printf("%d ",root->data);
	else if(level>1)
		{
			PrintGivenLevel(root->left,level-1);
			PrintGivenLevel(root->right,level-1);
		}	
}
void main()
{
	struct node *root=NULL;
	int n,i,data;
	printf("Enter No. of elements\n");
	scanf("%d",&n);
	printf("Enter elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		root=insert(root,data);
	}
	printf("Level Order Traversal : \n");
	LevelOrder(root);
	printf("\n");
	printf("Inorder traversal : \n");
	inorder(root);
	printf("\nHeight = %d\n",height(root));
	printf("\nTotal Nodes = %d\n",totalnodes(root));
	printf("\nInternal Nodes = %d\n",internalnodes(root));
	printf("\nExternal Nodes = %d\n",externalnodes(root));
	printf("Enter data to be deleted\n");
	scanf("%d",&data);
	root=deletenode(root,data);
	inorder(root);
}
