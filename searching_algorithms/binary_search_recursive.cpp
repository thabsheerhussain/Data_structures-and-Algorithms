#include <bits/stdc++.h> 
using namespace std;

int binarySearch(vector<int>& arr, int l, int r, int q) 
{ 
	if (r>=l) 
	{ 
		int mid = l+(r-l)/2; 
		if (arr[mid] == q) 
			return mid; 
		if (arr[mid] > q) 
			return binarySearch(arr, l, mid-1, q); 
		else
			return binarySearch(arr, mid+1, r, q); 
	} 
	return -1; 
} 

int main() 
{ 
	int n;
	cin>>n;

	vector<int> list(n);
	for(int i = 0 ; i<n ; i++)
	cin>>list[i];
	
	int query;
	cin>>query;
	
	int result = binarySearch(list, 0, n-1, query); 
	if(result==-1)
		cout<<"Not Found"<<"\n";
	else
		cout<<"Present at index: "<<result<<"\n";
} 
