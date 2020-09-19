/**
 * Title   : Biconnected Graph
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/biconnected-graph/0
 **/

#include<bits/stdc++.h>
using namespace std;

bool isBiconnectedUtil(int u, vector<vector<int> > adj, bool visited[], int discoveryTime[], int lowTime[], int parent[], int& time) {

    visited[u] = true;
    discoveryTime[u] = lowTime[u] = time++;

    int child  = 0;

    for (int i = 0; i < adj[u].size(); ++i) {

        int v = adj[u][i];

        if (!visited[v]) {

            ++child;
            parent[v] = u;

            if (!isBiconnectedUtil(v, adj, visited, discoveryTime, lowTime, parent, time))
                return false;

            lowTime[u] = min(lowTime[u], lowTime[v]);

            if (parent[u] == -1 && child > 1)
                return false;
            if (parent[u] != -1 && lowTime[v] >= discoveryTime[u])
                return false;
        }
        else if (v != parent[u])
            lowTime[u] = min(lowTime[u], discoveryTime[v]);
    }

    return true;
}

void isBiconnected(int V, vector<vector<int> > adj) {

    bool visited[V];
    int discoveryTime[V], lowTime[V], parent[V];

    memset(visited, false, sizeof(visited));
    memset(discoveryTime, -1, sizeof(discoveryTime));
    memset(lowTime, -1, sizeof(lowTime));
    memset(parent, -1, sizeof(parent));

    int time = 0;

    if (!isBiconnectedUtil(0, adj, visited, discoveryTime, lowTime, parent, time)) {
        cout << 0;
        return;
    }

    for (int i = 1; i < V; ++i) {
        if (!visited[i]) {
            cout << 0;
            return;
        }
    }

    cout << 1;
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n, e;
        cin >> n >> e;

        vector<vector<int> > adj(n);

        for (int i = 0; i < e; ++i) {
            int src, dest;
            cin >> src >> dest;
            adj[src].emplace_back(dest);
            adj[dest].emplace_back(src);
        }

        isBiconnected(n, adj);
        cout << '\n';
    }

    return 0;
}
