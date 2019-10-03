/*
    "BFS IMPLEMENTATION USING QUEUE CLASS IN CPP WITH ADJACENCY LIST"

    INPUT FORMAT:
    1. Input number of edges and nodes.
    2. Enter info of each edge i.e. goes from a to b 
    3. Here 1 is starting vertex for BFS
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int edges,nodes;
    cin>>edges>>nodes;
    
    // adjacency list for storing edges
    vector<vector<int>> adj(nodes+1);
    
    int a,b;
    for(int i=0 ; i<edges ; i++)
    {    
        // shows that an edge goes from 'a' to 'b'
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    // to mark nodes while traversing so that 
    // they are visited only once 
    vector<bool> visited(nodes+1,false);

    queue<int> q ;
    // taking 1 as starting vertex, can be any vetex
    q.push(1);
    // marking it as visited
    visited[1]=true;

    while(!q.empty())
    {
        int first = q.front();
        cout << first << endl;
        visited[first]=true;

        q.pop();
        
        // visiting all neighbours of 'first' node
        for(int i=0 ; i<adj[first].size() ; i++)
        {
            // if any neighbour is not visited, add to queue
            if(visited[adj[first][i]]==false)
            {
                q.push(adj[first][i]);
                visited[adj[first][i]]=true;    
            }
        }
    }
} 
