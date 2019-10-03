/*
	Note: Given list should be already sorted for Binary Search to work correctly
*/

#include <bits/stdc++.h> 
using namespace std;

int binarySearch(vector<int> &list, int l, int r, int q) 
{ 
	while(l<=r) 
	{ 
		int m = (l+r)/2; 
		// if 'q' matches with element at current index, return index
		if (list[m]==q) 
			return m;
		// if current element is smaller, we go to other half(right) to search
		if (list[m] < q) 
			l = m + 1; 
		// if current element is bigger, we go to other half(left) to search
		else
			r = m - 1; 
	} 
	return -1; // will indicate that we did not found 'q'
} 

int main() 
{ 
	// number of elements
	int n;
	cin>>n;
	
	vector<int> list(n);
	
	// input in sorted order
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
