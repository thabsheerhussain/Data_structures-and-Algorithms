/*
	"IMPLEMENTATION OF EFFICIENT DIJKSTRA USING PRIORITY QUEUE AND ADJACENCY LIST IN CPP"

	INPUT FORMAT:
	1. Give number of nodes and edges as input.
	2. Input edges info i.e. going from a to b having cost c 
	3. Give source and destination
*/

#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9  

int main()
{
	int nodes,edges;
	cin>>nodes>>edges;

	vector<vector<pair<int,int>>> adj(nodes+1);

	int a,b,c;
	for(int i = 0 ; i<edges ; i++)
	{
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}

	int src, des;
	cin>>src>>des;

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,src});

	vector<int> dist(nodes+1,INF);
	dist[src] = 0;

	while(!pq.empty())
	{
	    int par = pq.top().second; 
	    int dis = pq.top().first;   
	    pq.pop();

	    for(int i = 0 ; i<adj[par].size() ; i++)
	    {
	        int child = adj[par][i].first;
	        int cost  = adj[par][i].second;

	        if(dis+cost<dist[child])
	        {
	            dist[child] = dis+cost;
	            pq.push({dist[child],child});
	        }
	    }
	}

	cout<<"Shortest distance from "<<src<<" to "<<des<<" is "<<dist[des]<<"\n";
}
