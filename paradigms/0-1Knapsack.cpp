/*
    "Implementation of 0-1 Knapsack"

    Given:
    1. Capacity of knapsack/total weight knapsack can carry
    2. Number of items with (item weight,its value)

    To do:
    1. Pick items in such a way that total weight is smaller than capacity 
    2. and sum of values of pickde items is maximized

    Note: In 0-1 knapsack either we pick an item or not, we can not divide any item/choose item partially
*/

# include <bits/stdc++.h>
  using namespace std;

int ks(vector<pair<int,int>> &list, int n, int c)
{
    // base case 
    // if no items are left/capacity is fulled
    if(n==0 || c==0)
        return 0;

    // if current item has weight>capacity 
    // no need to consider it, move to n-1
    else if(list[n].first>c)
        return ks(list, n-1, c);

    // We get two cases: 
    // 1. if we put it in knapsack
    // 2. if we do not pick it and move further 
    else
    {
        // we take max of both cases 
        return max( ks(list, n-1, c) , list[n].second + ks(list,n-1,c-list[n].first) );
    }
}

int main()
{
    // capacity of knapsack,total items to pick from
    int capacity,items;
    cin>>capacity>>items;

    vector<pair<int,int>> list(items+1);

    // item weight, item value
    for(int i = 1 ; i<=items ; i++)
    cin>>list[i].first>>list[i].second;

    cout<<ks(list, items, capacity)<<endl;
}   
