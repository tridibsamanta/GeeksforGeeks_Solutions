/**
 * Title   : Bridge Edge in Graph
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1/
 **/

// { Driver Code Starts
// Initial template
#include <bits/stdc++.h>
using namespace std;

bool isBridge(list<int> adj[], int V, int u, int v);
// Driver Program
int main() {

    int T;
    cin >> T;
    while (T--) {
        int s, N;
        cin >> s >> N;
        list<int> *adj = new list<int>[s];
        for (int i = 0; i < N; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        int a, b;
        cin >> a >> b;

        if (isBridge(adj, s, a, b))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}
// } Driver Code Ends


// your task is to complete this function

/*
adj : adjacency list of the graph
V : Number of vertices
s,e : End vertices of the given edge
*/

void isBridgeUtil(int u, list<int> adj[], int V, int s, int e, bool visited[], int discTime[], int lowTime[], int parent[], int &time, bool &bridgeFound) {

    visited[u] = true;
    discTime[u] = lowTime[u] = time++;

    list<int> :: iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i) {

        int v = *i;

        if (!visited[v]) {

            parent[v] = u;

            isBridgeUtil(v, adj, V, s, e, visited, discTime, lowTime, parent, time, bridgeFound);

            lowTime[u] = min(lowTime[u], lowTime[v]);

            if (lowTime[v] > discTime[u]) {
                if ((u == s && v == e) || (v == s && u == e)) {
                    bridgeFound = true;
                    break;
                }
            }
        }
        else if (v != parent[u])
            lowTime[u] = min(lowTime[u], discTime[v]);
    }
}

bool isBridge(list<int> adj[], int V, int s, int e) {

    bool visited[V];
    int discTime[V], lowTime[V], parent[V];
    int time = 0;
    bool bridgeFound = false;

    for (int i = 0; i < V; ++i) {
        visited[i] = false;
        discTime[i] = -1;
        lowTime[i] = -1;
        parent[i] = -1;
    }

    for (int i = 0; i < V; ++i) {
        if (!visited[i] && !bridgeFound)
            isBridgeUtil(i, adj, V, s, e, visited, discTime, lowTime, parent, time, bridgeFound);
    }

    return bridgeFound;
}
