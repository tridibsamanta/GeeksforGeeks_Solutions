/**
 * Title   : Detect cycle in an undirected graph
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/

bool isCyclicUtil(vector<int> adj[], int V, int s, bool visited[], int parent) {

    visited[s] = true;

    for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
        if (!visited[*i]) {
            if (isCyclicUtil(adj, V, *i, visited, s))
                return true;
        }
        else if (*i != parent)
            return true;
    }

    return false;
}


bool isCyclic(vector<int> g[], int V) {

    bool *visited = new bool[V];
    for(int i = 0; i < V; ++i)
        visited[i] = false;

    for (int i = 0; i < V; ++i)
        if (!visited[i] && isCyclicUtil(g, V, i, visited, INT_MIN))
            return true;

    return false;
}

// { Driver Code Starts.


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;

        // array of vectors to represent graph
        vector<int> adj[V];

        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;

            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends
