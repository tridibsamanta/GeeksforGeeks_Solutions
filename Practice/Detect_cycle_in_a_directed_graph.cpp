/**
 * Title   : Detect cycle in a directed graph
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

bool isCyclicUtil(int v, vector<int> adj[], bool visited[], bool recStack[]) {

    visited[v] = true;
    recStack[v] = true;

    for (auto i : adj[v]) {
        if (!visited[i] && isCyclicUtil(i, adj, visited, recStack))
            return true;
        else if (recStack[i])
            return true;
    }

    recStack[v] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {

    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for (int i = 0; i < V; ++i) {
        visited[i] = false;
        recStack[i] = false;
    }
    for (int i = 0; i < V; ++i)
        if (!visited[i] && isCyclicUtil(i, adj, visited, recStack))
            return true;
    return false;
}

// { Driver Code Starts.

int main() {

	int t;
	cin >> t;

	while(t--){

	    int v, e;
	    cin >> v >> e;

	    vector<int> adj[v];

	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }

	    cout << isCyclic(v, adj) << endl;

	}

	return 0;
}  // } Driver Code Ends
