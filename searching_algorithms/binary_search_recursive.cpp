#include <bits/stdc++.h>
 using namespace std;

int binarysearch(vector<int> &list, int f, int l, int search )
{
	if(l>=1)
	{
		int mid=(f+l)/2;
		if(list[mid]==search)
			return mid;
		else if(list[mid]>search)
			return binarysearch(list, f, mid-1, search);
		else
			return binarysearch(list, mid+1, l, search);
	}
	return -1;
}

int main()
{
	int n;
	cin>>n;

	vector<int> list(n);
	for( int i=0  ; i<n ;  i++)
	{
		cin>>list[i];
	}

	int query;
	cin>>query;

	int f=0, l=(n-1), r;
	r = binarysearch(list, f, l, query);
	if(r==-1)
		cout<<query<<"Not found!"<<"\n";
	else
		cout<<query<<"Found at index "<<r<<"\n";
}

