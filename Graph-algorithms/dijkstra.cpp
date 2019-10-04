/*
	"IMPLEMENTATION OF EFFICIENT DIJKSTRA USING PRIORITY QUEUE AND ADJACENCY LIST IN CPP"

	INPUT FORMAT:
	1. Give number of nodes and edges as input.
	2. Input edges info i.e. going from a to b having cost c 
	3. Give source and destination
*/

#include <bits/stdc++.h>
using namespace std;

// initial distance for each node is set to infinite
#define INF (int)1e9  

int main()
{
	int nodes,edges;
	cin>>nodes>>edges;
	
	// adjacency list to store edge + its cost
	vector<vector<pair<int,int>>> adj(nodes+1);

	int a,b,c;
	for(int i = 0 ; i<edges ; i++)
	{
		// indicated edge from node 'a' to 'b' having cost 'c'
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	
	// source and destination node
	int src, des;
	cin>>src>>des;
	
	// priority queue to process Dijkstra, makes it more efficient
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	
	// pushing distance from src to src i.e. 0 and node itself
	pq.push({0,src});
	
	// to store distance from source node to every other node
	// initially infinity for all other nodes
	// distance to itself is 0
	vector<int> dist(nodes+1,INF);
	dist[src] = 0;

	while(!pq.empty())
	{
	    // 'par' is node are currently at
	    // 'dis' is distance from source to 'par'
	    int par = pq.top().second; 
	    int dis = pq.top().first;  
		
	    pq.pop();
		
	    // visiting neighbours of 'par'
	    // to get more shortest distance 
	    for(int i = 0 ; i<adj[par].size() ; i++)
	    {
	        int child = adj[par][i].first;
	        int cost  = adj[par][i].second;
		
		// relaxating the edge 
	        // i.e. if there exits even shortest distance, then update it
		// and push that node to priority queue
	        if(dis+cost<dist[child])
	        {
	            dist[child] = dis+cost;
	            pq.push({dist[child],child});
	        }
	    }
	}

	cout<<"Shortest distance from "<<src<<" to "<<des<<" is "<<dist[des]<<"\n";
}
