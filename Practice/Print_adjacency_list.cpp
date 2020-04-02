/**
 * Title   : Print adjacency list
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/print-adjacency-list/0
 **/

#include<iostream>
using namespace std;

struct AdjListNode {
    int data;
    AdjListNode* next;
};

struct AdjList {
    AdjListNode *head;
};

struct Graph{
    int vertices;
    AdjList *arr;
};

AdjListNode* newAdjListNode(int data) {
    AdjListNode* newNode = new AdjListNode();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = new Graph();
    graph->vertices = vertices;
    graph->arr = new AdjList[vertices];
    for(int i = 0; i < vertices; i++)
        graph->arr[i].head = NULL;
    return graph;
}

void addEdge(Graph* graph, int source, int destination) {

    AdjListNode* tempNode = newAdjListNode(destination);

    AdjListNode* root = graph->arr[source].head;

    if(graph->arr[source].head == NULL)
        {
            tempNode->next = graph->arr[source].head;
            graph->arr[source].head = tempNode;
        }
    else {
        while(root->next != NULL)
            root = root->next;

        tempNode->next = root->next;
        root->next = tempNode;
    }

    tempNode = newAdjListNode(source);
    root = graph->arr[destination].head;

    if(graph->arr[destination].head == NULL)
    {
        tempNode->next = graph->arr[destination].head;
        graph->arr[destination].head = tempNode;
    }
    else {
        while(root->next != NULL)
            root = root->next;

        tempNode->next = root->next;
        root->next = tempNode;
    }
}

void printGraph(Graph* graph) {
    for(int i = 0; i < graph->vertices; ++i) {
        AdjListNode* root = graph->arr[i].head;
        cout << i;
        while(root != NULL) {
            cout << "-> " << root->data;
            root = root->next;
        }
        cout << "\n";
    }
}

int main() {

    int T;
    cin >> T;

    while(T--) {

    int V, E;
    cin >> V >> E;

    Graph* graph = createGraph(V);

    for(int i=0; i < E; i++) {
        int source, destination;
        cin >> source >> destination;
        addEdge(graph, source, destination);
    }
    printGraph(graph);
    }
}
