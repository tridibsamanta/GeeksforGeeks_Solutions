/**
 * Title   : Euler circuit and Path
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/euler-circuit-and-path/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
#include <list>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V)   {this->V = V; adj = new list<int>[V]; }
    ~Graph() { delete [] adj; }
    void addEdge(int v, int w);
    int isEulerian();
    bool isConnected();
    void DFSUtil(int v, bool visited[]);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
void test(Graph &g)
{
    int res = g.isEulerian();
    if (res == 0)
        cout << "0\n";    //none
    else if (res == 1)
        cout << "1\n";    //Euler path
    else
        cout << "2\n";    //Euler cycle
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int v,e;
		cin>> v>>e;
		Graph g1(v);
		for(int i=0;i<e;i++){
			int a,b;
			cin>>a>>b;
		g1.addEdge(a, b);
		}
		test(g1);
	}
    return 0;
}// } Driver Code Ends


/*Complete the function below*/

bool Graph::isConnected() {

    bool visited[V];
    int i;
    for (i = 0; i < V; ++i)
        visited[i] = false;

    for (i = 0; i < V; ++i)
        if (adj[i].size() > 0)
            break;

    if (i == V)
        return true;

    DFSUtil(i, visited);

    for (i = 0; i < V; ++i)
        if (!visited[i] && adj[i].size() > 0)
            return false;

    return true;
}

int Graph::isEulerian() {

    if (!isConnected())
        return 0;

    int oddDegreeVertex = 0;
    for (int i = 0; i < V; ++i)
        if (adj[i].size() & 1)
            ++oddDegreeVertex;

    if (oddDegreeVertex > 2)
        return 0;

    return (oddDegreeVertex) ? 1 : 2;
}
