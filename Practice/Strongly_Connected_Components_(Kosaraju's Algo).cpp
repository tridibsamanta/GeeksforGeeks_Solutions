/**
 * Title   : Strongly Connected Components (Kosaraju's Algo)
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/

void dfsUtil(int v, bool visited[], vector<int> adj[], stack<int> &s) {
    visited[v] = true;
    vector <int> :: iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            dfsUtil(*i, visited, adj, s);
    s.push(v);
}

void dfsTransposeUtil(int v, bool visited[], vector<int> adjT[]) {
    visited[v] = true;
    vector <int> :: iterator i;
    for (i = adjT[v].begin(); i != adjT[v].end(); ++i)
        if (!visited[*i])
            dfsTransposeUtil(*i, visited, adjT);
}

int kosaraju(int V, vector<int> adj[]) {

    stack<int> s;

    bool *visited = new bool[V];
    for (int i = 0; i < V; ++i)
        visited[i] = false;

    for (int i = 0; i < V; ++i)
        if (!visited[i])
            dfsUtil(i, visited, adj, s);

    // Form transpose of the graph
    vector<int> adjT[V];
    for (int i = 0; i < V; ++i) {
        vector <int> :: iterator itr;
        for (itr = adj[i].begin(); itr != adj[i].end(); ++itr)
            adjT[*itr].emplace_back(i);
    }

    // Pop from stack and perform DFS on transpose graph
    for (int i = 0; i < V; ++i)
        visited[i] = false;

    int sccCount = 0;
    while (!s.empty()) {
        int t = s.top();
        s.pop();
        if (!visited[t]) {
            dfsTransposeUtil(t, visited, adjT);
            ++sccCount;
        }
    }

    return sccCount;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int m, n;
        vector<int> adj[a];
        for (int i = 0; i < b; i++) {
            cin >> m >> n;
            adj[m].push_back(n);
        }
        cout << kosaraju(a, adj) << endl;
    }
    return 0;
}
  // } Driver Code Ends
