/**
 * Title   : Strongly connected component (Tarjans's Algo)
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/strongly-connected-component-tarjanss-algo/0
 **/

#include<bits/stdc++.h>
using namespace std;

void findSCCUtil(int u, int discoveryTime[], int lowTime[], stack<int>& s, bool inStack[], vector<vector<int> > adj, int &time) {

    discoveryTime[u] = lowTime[u] = time++;
    s.push(u);
    inStack[u] = true;

    vector<int> :: iterator itr;
    for (itr = adj[u].begin(); itr != adj[u].end(); ++itr) {

        int v = *itr;

        if (discoveryTime[v] == -1) {
            findSCCUtil(v, discoveryTime, lowTime, s, inStack, adj, time);
            lowTime[u] = min(lowTime[u], lowTime[v]);
        }
        else if (inStack[v] == true) {
            lowTime[u] = min(lowTime[u], discoveryTime[v]);
        }
    }

    if (lowTime[u] == discoveryTime[u]) {
        int curr;
        while (s.top() != u) {
            curr = s.top();
            cout << curr << ' ';
            s.pop();
            inStack[curr] = false;
        }
        curr = s.top();
        cout << curr << ',';
        s.pop();
        inStack[curr] = false;
    }
}

void findSCC(int V, vector<vector<int> > adj) {

    int discoveryTime[V];
    int lowTime[V];
    bool inStack[V];

    memset(discoveryTime, -1, sizeof(discoveryTime));
    memset(lowTime, -1, sizeof(lowTime));
    memset(inStack, false, sizeof(inStack));

    stack<int> s;

    int time = 0;

    for (int i = 0; i < V; ++i) {
        if (discoveryTime[i] == -1) {
            findSCCUtil(i, discoveryTime, lowTime, s, inStack, adj, time);
        }
    }
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;

        vector<vector<int> > adj(n);

        for (int i = 0; i < m; ++i) {
            int src, dest;
            cin >> src >> dest;
            adj[src].emplace_back(dest);
        }

        findSCC(n, adj);
        cout << '\n';
    }

    return 0;
}
