//Dijkstra Algorithm implemented in C 
//Graph Algorithm. with Priorty queue implemeted with heap.
#include<stdio.h>
int b[10];
//Struct for elements for graph
struct node{
	int v;
	int d;
	int p;
}arr[10],set[10];
void intialise_single_source(int n,int s)
{
	int i;
	for(i=0;i<n;i++)
	{
		arr[i].v=i;
		arr[i].d=10000;
		arr[i].p=-1;
	}
	arr[s].d=0;
}
void min_heapify(int heap_size,int i)
{
	int smallest;
	struct node t;
	int l=2*i+1;
	int r=2*i+2;
	if(l<heap_size&&arr[l].d<arr[i].d)
	{
		smallest=l;
	}
	else
	{
		smallest=i;
	}
	if(r<heap_size&&arr[r].d<arr[smallest].d)
	{
		smallest=r;
	}
	if(smallest!=i)
	{
		t=arr[i];
		arr[i]=arr[smallest];
		arr[smallest]=t;
		b[arr[smallest].v]=smallest;
		b[arr[i].v]=i;
		min_heapify(heap_size,smallest);
	}
}

void build_min_heap(int heap_size)
{
	int i;
	for(i=(heap_size/2)-1;i>=0;i--)
		min_heapify(heap_size,i);
}
struct node heap_extract_min(int heap_size)
{
	struct node max;
	max=arr[0];
	b[arr[0].v]=heap_size-1;
	arr[0]=arr[heap_size-1];
	b[arr[0].v]=0;
	return max;
}
int main()
{
	int a[10][10],s,i,j,n,m,heap_size;//a[10][10] is used to store graph
	struct node u;
	printf("enter the number of nodes in graph ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("enter the weight of edge %d->%d ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("enter the source node ");
	scanf("%d",&s);
	heap_size=n;
	for(i=0;i<n;i++)
	{
		b[i]=i;
	}
	intialise_single_source(n,s);
	build_min_heap(heap_size);
	m=0;
	while(heap_size!=0)
	{
		u=heap_extract_min(heap_size);
		heap_size--;
		min_heapify(heap_size,0);
		set[m]=u;
		m++;
		for(i=0;i<n;i++)
		{
			if(a[u.v][i]!=0)
			{
				if(arr[b[i]].d>u.d+a[u.v][i])
				{
					arr[b[i]].d=u.d+a[u.v][i];
					arr[b[i]].p=u.v;
				}
			}
		}
		build_min_heap(heap_size);
	}
	printf("\nthe solution is\n");
	for(i=1;i<n;i++){
		printf("%d->%d the minimum weight from source %d to %d is %d\n",set[i].p,set[i].v,s,set[i].v,set[i].d);
	}
	return 0;
}
