/**
 * Title   : Circle of strings
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/circle-of-strings/0
 **/

#include<bits/stdc++.h>
using namespace std;

#define ALPHABETS 26

class Graph {
private:
    int totalVertices;
    vector<int> *adj;
    int *in;
    bool isStronglyConnected();
    void dfs(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int src, int dest);
    bool isCircleOfStrings();
    Graph getTranspose();
};

Graph::Graph(int V) {
    totalVertices = V;
    adj = new vector<int>[V];
    in = new int[V];
    for (int i = 0; i < V; ++i)
        in[i] = 0;
}

void Graph::addEdge(int src, int dest) {
    adj[src].emplace_back(dest);
    in[dest]++;
}

Graph Graph::getTranspose() {
    Graph g(totalVertices);
    for (int v = 0; v < totalVertices; ++v) {
        vector<int> :: iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            g.adj[*i].emplace_back(v);
    }
    return g;
}

void Graph::dfs(int v, bool visited[]) {
    visited[v] = true;
    vector<int> :: iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            dfs(*i, visited);
}

bool Graph::isStronglyConnected() {

    bool visited[totalVertices];
    for (int i = 0; i < totalVertices; ++i)
        visited[i] = false;

    int v;
    for (v = 0; v < totalVertices; ++v)
        if (adj[v].size() > 0)
            break;

    dfs(v, visited);

    for (int i = 0; i < totalVertices; ++i)
        if (adj[i].size() > 0 && !visited[i])
            return false;

    Graph gT = getTranspose();

    for (int i = 0; i < totalVertices; ++i)
        visited[i] = false;

    gT.dfs(v, visited);

    for (int i = 0; i < totalVertices; ++i)
        if (adj[i].size() > 0 && !visited[i])
            return false;

    return true;
}

bool Graph::isCircleOfStrings() {

    if (!isStronglyConnected())
        return false;

    for (int i = 0; i < totalVertices; ++i)
        if (adj[i].size() != in[i])
            return false;

    return true;
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        Graph g(ALPHABETS);

        int n;
        cin >> n;

        while(n--) {

            string s;
            cin >> s;

            g.addEdge(s[0] - 'a', s[s.length()-1] - 'a');
        }

        if (g.isCircleOfStrings())
            cout << 1 << '\n';
        else
            cout << 0 << '\n';

    }

    return 0;
}
