#include <bits/stdc++.h> 
using namespace std;

int binarySearch(vector<int> &list, int l, int r, int q) 
{ 
	while(l<=r) 
	{ 
		int m = (l+r)/2; 
		if (list[m]==q) 
			return m; 
		if (list[m] < q) 
			l = m + 1; 

		else
			r = m - 1; 
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
