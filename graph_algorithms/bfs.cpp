/*
  This Program Implements a BFS Search on a graph and tells the level of nodes from a source nodes which is to be entered.
*/
#include<stdio.h>
#include<malloc.h>
typedef struct node *link;
typedef struct node {
	int tonode,weight;
	link next;
}node1;
link *head,*ptr;
int *queue;
int f=-1;
int r=-1;
int n;
void create(int n){
	queue=(int *)calloc(sizeof(int),n);
}
int isempty(){
	if(f==-1){
	//printf("queue is empty");
	return 1;
	}
	else
	return 0;
}
int isfull(int n){
	if(f==0&&r==n-1){
//	printf("stack is full");
	return 1;}
	else
	return 0;
}
void enqueue(int e,int n){
	if(!isfull(n)){
		queue[++r]=e;
		if(f==-1)
		f=0;
	}
}
int dequeue(){
	int x=-1;
	if(!isempty()){
		 x=queue[f];
		if(f==r)
		f=r=-1;
		else{
			
		queue[f]=NULL;
		f++;}
}
return x;
}

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
void bfs(link *head,int *state,int* parent,int n,int s,int * dis){
	link temp;
	int u;
	state[s]=1;
	parent[s]=-1;
	dis[s]=0;
	enqueue(s,n);
	while(!isempty()){
		u=dequeue();
		temp=head[u];
	while(temp!=NULL){
		if(state[temp->tonode]==0){
			state[temp->tonode]=1;
			parent[temp->tonode]=u;
			dis[temp->tonode]=dis[u]+1;
			enqueue(temp->tonode,n);	
		}
		temp=temp->next;
	}
	state[u]=2;
	}
}
main(){
	int n,i,j,x,y,w,k=0;
	link trs;
	int *state,*parent,*dis;
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	head =(link*)malloc(n*sizeof(link));
	ptr	=(link*)malloc(n*sizeof(link));
	state=(int *)malloc(n*sizeof(int));
	parent=(int *)malloc(n*sizeof(int));
	dis=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		head[i]=NULL;
		ptr[i]=NULL;
		state[i]=0;
		parent[i]=-1;
		dis[i]=-1;
	}
	x=y=w=0;
	printf("Enter nodes to be connected and its weight \n and -1 -1 -1 for no input\n");
	while(1){
		scanf("%d%d%d",&x,&y,&w);
		if(x!=-1){
		insert(x,y,w);
		insert(y,x,w);
		}
		else
		break;
	}
	display(n);
	create(n);
	int s;
	printf("Enter Source\n");
	scanf("%d",&s);
	bfs(head,state,parent,n,s,dis);
	for(i=0;i<n;i++){
		printf("%d-->%d\n",i,dis[i]);
	}

}
