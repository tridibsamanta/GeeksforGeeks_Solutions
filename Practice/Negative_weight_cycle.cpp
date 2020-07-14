/**
 * Title   : Negative weight cycle
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/negative-weight-cycle/0
 **/

#include<bits/stdc++.h>
using namespace std;

void detectNegativeWeightCycle(int totalVertices, vector<pair<int, int> > adj[]) {

    vector<int> distance(totalVertices, INT_MAX);
    distance[0] = 0;

    for (int k = 0; k < totalVertices - 1; ++k) {

        for (int currVertex = 0; currVertex < totalVertices; ++currVertex) {
            for (auto i : adj[currVertex]) {
                int adjVertex = i.first;
                int weight = i.second;
                if (distance[adjVertex] > distance[currVertex] + weight) {
                    distance[adjVertex] = distance[currVertex] + weight;
                }
            }
        }
    }

    for (int currVertex = 0; currVertex < totalVertices; ++currVertex) {
        for (auto i : adj[currVertex]) {
            int adjVertex = i.first;
            int weight = i.second;
            if (distance[adjVertex] > distance[currVertex] + weight) {
                cout << 1;
                return;
            }
        }
    }

    cout << 0;
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;

        vector<pair<int, int> > adj[n];

        int src, dest, weight;
        for (int i = 0; i < m; ++i) {
            cin >> src >> dest >> weight;
            adj[src].emplace_back(make_pair(dest, weight));
        }

        detectNegativeWeightCycle(n, adj);
        cout << '\n';
    }
    return 0;
}
