/**
 * Title   : Floyd Warshall
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall/0
 **/

#include<bits/stdc++.h>
using namespace std;

const unsigned int INF = 1000000007;

void findShortestPath(int totalVertices, vector<pair<int, int> > adj[]) {

    vector<vector<int> > distance(totalVertices, vector<int> (totalVertices, INT_MAX));

    for (int i = 0; i < totalVertices; ++i)
        distance[i][i] = 0;

    for (int v = 0; v < totalVertices; ++v) {
        for (auto i : adj[v]) {
            int adjVertex = i.first;
            int weight = i.second;
            distance[v][adjVertex] = weight;
        }
    }

    for (int k = 0; k < totalVertices; ++k) {

        for (int i = 0; i < totalVertices; ++i) {

            for (int j = 0; j < totalVertices; ++j) {

                if (distance[i][k] == INT_MAX || distance[k][j] == INT_MAX)
                continue;

                if (distance[i][j] > distance[i][k] + distance[k][j])
                    distance[i][j] = distance[i][k] + distance[k][j];
            }
        }
    }

    for (int i = 0; i < totalVertices; ++i) {
        for (int j = 0; j < totalVertices; ++j) {
            if (distance[i][j] == 10000000)
            cout << "INF ";
        else
            cout << distance[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {

    int t;
    cin >> t;
    while (t--) {

    int n;
    cin >> n;

    vector<pair<int, int> > adj[n];

    int weight;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> weight;
            if (weight != 0 || weight != INF)
                adj[i].emplace_back(make_pair(j, weight));
        }
    }

    findShortestPath(n, adj);

    }
    return 0;
}
