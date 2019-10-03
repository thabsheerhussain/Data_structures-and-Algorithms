#include<bits/stdc++.h>
using namespace std;
int binarysearch(vector<int> &a,int l,int r,int x){
	
	if(r>=l){
		int mid = l + (r-l)/2;
		
		if(a[mid] == x){
			return mid;
		}
		if(a[mid] > x)
			return binarysearch(a, l, mid-1,x);
		else
			return binarysearch(a, mid+1, r,x);
	}
	//if we don't find the val we return INT_MIN
	return INT_MIN;
}

int main(){
	
	//Access binary Search from here
	vector<int> a;
	// Add elements in a;
	//if the array is not sorted you can sort it using stl function
	sort(a.begin(),a.end());
	// x is the element to search for;
	int x;
	cout<<"Enter Element to Search"<<endl;
	cin>>x;
	int n = a.size();
	int ans = binarysearch(a,0,n-1,x);
	if(ans != INT_MIN)
		cout<<"Element is found"<<endl;
	else
		cout<<"Element is not found"<<endl;
	return 0;
}
