/* 
Problem: Given an array arr[] of n elements, write a function to search a given element x in arr[].

Examples :

Input : arr[] = {10, 20, 80, 30, 60, 50, 
                     110, 100, 130, 170}
          x = 110
Output : 6
Element x is present at index 6

*/

#include <iostream> 
using namespace std; 
  
int search(int arr[], int n, int query) 
{ 

    int i; 
    for (i = 0; i < n; i++) 
        if (arr[i] == query) 
            return i; 
    return -1; 
} 
  
int main(void) 
{ 
    // number of elements
	  int n;
	  cin>>n;

    // declaring array for storing inputs
    int arr[n];

    // Taking Input from user
	  for(int i = 0 ; i<n ; i++)
		  cin>>arr[i];

    // element to be searched
	  int query;
	  cin>>query;

    int result = search(arr, n, query); 
   (result == -1)? cout<<"Element is not present in array" 
                 : cout<<"Element is present at index " <<result; 
   return 0; 
} 