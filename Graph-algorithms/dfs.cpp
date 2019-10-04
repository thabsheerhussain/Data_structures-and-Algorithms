/*
    "DFS IMPLEMENTATION USING RECUSTION IN CPP WITH ADJACENCY LIST"

    INPUT FORMAT:
    1. Input number of edges and nodes.
    2. Enter info of each edge i.e. goes from a to b 
    3. x is starting vertex for DFS
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> visited, int x)
{	
	// marking node 'x' as visited
	visited[x] = true;
	cout<<x<<"\n";
	
	// checking all neighbours of node 'x'
	for(int i=0 ; i<adj[x].size() ; i++)
    	{
		// if any neighbour is unvisited, traverse through it
		if(visited[adj[x][i]]==false)
		{
		       dfs(adj,visited,adj[x][i]);
		}
    	}
}

int main()
{
    int edges,nodes;
    cin>>edges>>nodes;
    
    //	adjacency list to store edges 
    vector<vector<int>> adj(nodes+1);
    
    int a,b;
    for(int i=0 ; i<edges ; i++)
    {    
	// indicates an edge goes from node 'a' to 'b'
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
	
    //to mark nodes while traversing
    // to make sure every node is visited once
    vector<bool> visited(nodes+1,false);

    dfs(adj,visited,1);
} 
