#include<stdio.h>
#include<malloc.h>
void build_max_heap(int a[],int n);
void heapsort(int a[],int n);
void heapify(int a[],int n,int i);
int n;
main(){
	int i;
	int *a;
	printf("Enter number of element\n");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("enter elements\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	heapsort(a);
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
}
int extract(int a[]){
	int max=a[0];
	a[0]=a[n-1];
	n=n-1;
	heapify(a,0);
	return max;
}
void heapsort(int a[]){
	build_max_heap(a,n);
	int i,temp;
	for(i=n-1;i>0;i--){
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		n--;
		heapify(a,0);
	}
}
void build_max_heap(int a[]){
	int i,x;
	x=(n/2)-1;
	for(i=x;i>=0;i--){
		heapify(a,i);
	}
}
void heapify(int a[],int i){
	int l=2*i+1;
	int r=2*i+2;
	int largest;
	int temp;
	if(l<n&&a[l]>a[i])
	largest=l;
	else
	largest=i;
	if(r<n&&a[r]>a[largest])
	largest=r;
	if(largest!=i){
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		heapify(a,n,largest);
	}
}
 
