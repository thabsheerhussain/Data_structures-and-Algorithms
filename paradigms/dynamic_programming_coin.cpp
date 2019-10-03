#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define INF 1000000000000;
int m;
long dp[255][52];
long getWays(long n, vector<long> &c,int i) {
    if(n<0||i>=m)
        return 0;
    if(n==0)
        return 1;
    if(dp[n][i]!=-1){
        return dp[n][i];
	}
    long ans = 0;
    ans=getWays(n-c[i],c,i)+getWays(n,c,i+1);
    dp[n][i]=ans;
    return ans;

}

int main(){
    long n;
    cin>>n;
    cin>>m;
    memset(dp,-1,sizeof(dp));
    vector<long> c(m);
    for(auto &x:c)
        cin>>x;
    long ways = getWays(n, c,0);

    cout<<ways<<endl;
    return 0;
}
