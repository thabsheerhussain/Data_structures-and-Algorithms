#include<stdio.h>
#include<malloc.h>
typedef struct node *link;
typedef struct node {
	int tonode,weight;
	link next;
}node1;
link *head,*ptr;
void insert(int i,int x,int w){
	link temp;
	temp=(link)malloc(sizeof(node1));
	temp->tonode=x;
	temp->weight=w;
	temp->next=NULL;
	if(head[i]==NULL){
		head[i]=temp;
		ptr[i]=temp;
	}
	else{
	ptr[i]->next=temp;
	ptr[i]=temp;
	}
}
void display(int n){
	link trs;
	printf("\n");
	int i=0;
	link* trs1=head;
	for(i=0;i<n;i++){
		printf("%d---->",i);
	for(trs=trs1[i];trs;trs=trs->next)
		printf("(%d,%d)\t",trs->tonode,trs->weight);
	printf("\n");
	}
}

void dfs_visit(link *head,int *state,int* parent,int i){
	link temp;
	temp=head[i];
	state[i]=1;
	while(temp!=NULL){
		if(state[temp->tonode]==0){
			parent[temp->tonode]=i;
			dfs_visit(head,state,parent,temp->tonode);
		}
		temp=temp->next;
	}
	state[i]=2;
}
void dfs(link *head,int *state,int* parent,int n){
	int i;
	for(i=0;i<n;i++){
		if(state[i]==0){
			dfs_visit(head,state,parent,i);
		}
	}
}
main(){
	int n,i,j,x,y,w,k=0;
	link trs;
	int *state,*parent;
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	head =(link*)malloc(n*sizeof(link));
	ptr	=(link*)malloc(n*sizeof(link));
	state=(int *)malloc(n*sizeof(int));
	parent=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		head[i]=NULL;
		ptr[i]=NULL;
		state[i]=0;
		parent[i]=-1;
	}
	
	
	x=y=w=0;
	printf("Enter nodes to be connected and its weight \n and -1 -1 -1 for no input");
	while(1){
		scanf("%d%d%d",&x,&y,&w);
		if(x!=-1){
		insert(x,y,w);
		}
		else
		break;
	}
	display(n);
	dfs(head,state,parent,n);

}
