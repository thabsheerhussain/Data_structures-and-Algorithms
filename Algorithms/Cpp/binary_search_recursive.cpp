/*
	Note: Given list should be already sorted for Binary Search to work correctly
*/

#include <bits/stdc++.h> 
using namespace std;

int binarySearch(vector<int>& arr, int l, int r, int q) 
{ 
	if (r>=l) 
	{ 
		int mid = l+(r-l)/2; 
		// if 'q' matches with element at current index, return index
		if (arr[mid] == q) 
			return mid; 
		// if current element is bigger, we go to other half(left) to search
		if (arr[mid] > q) 
			return binarySearch(arr, l, mid-1, q); 
		// if current element is smaller, we go to other half(right) to search
		else
			return binarySearch(arr, mid+1, r, q); 
	} 
	return -1; // will indicate that we did not found 'q'
} 

int main() 
{ 
	int n;
	cin>>n;
	
	// input in sorted order
	vector<int> list(n);
	for(int i = 0 ; i<n ; i++)
	cin>>list[i];
	
	// element to be searched
	int query;
	cin>>query;
	
	int result = binarySearch(list, 0, n-1, query); 
	if(result==-1)
		cout<<"Not Found"<<"\n";
	else
		cout<<"Present at index: "<<result<<"\n";
} 
