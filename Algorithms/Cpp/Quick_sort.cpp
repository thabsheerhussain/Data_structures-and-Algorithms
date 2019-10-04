// Quick sort - O(log n)

#include<bits/stdc++.h>
using namespace std;

void printArray(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

// Quick Sort (Randomized , using fn shuffle we shuffle elements so that if sorted aaray comes , it becomes unsorted)

void shuffle(int a[],int s,int e){
	int i,j;
	srand(time(NULL));
	
	for(i=e;i>0;i--){
		j = rand()%(i+1);
		swap(a[i],a[j]);
	}
}
// Partition function makes the array such that element less than pivot element comes before it and
// elements greater than pivot moved after it. It is done recursively until the array is sorted.
// Here pivot element is always last element of array.
int partition(int a[],int s,int e){
	int i=s-1;
	int j=s;
	
	for(;j<e;j++){
		if(a[j]<a[e]){
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[e]);
	return i+1;
}

void quick_Sort(int a[],int s,int e){
	if(s>=e)
	return ;
	
	int p = partition(a,s,e);
	
	quick_Sort(a,s,p-1);
	quick_Sort(a,p+1,e);
}

signed main(){
	
	
	int b[] = { 2,1,5,8,4};
	cout<<"Initial Array :- ";
	printArray(b,5);
    shuffle(b,0,4);
    cout<<"\nShuffled Array :- ";
	printArray(b,5);
	quick_Sort(b,0,4);
	cout<<"\nSorted Array :- ";
	printArray(b,5); 
		
}



