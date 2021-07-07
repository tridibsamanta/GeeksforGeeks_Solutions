/**
 * Title   : Boundary Traversal of binary tree
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

 // } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    void getLeftBoundaryNodes(Node *root, vector<int> &nodes) {

        if (!root)
            return;

        if (root -> left) {
            nodes.emplace_back(root -> data);
            getLeftBoundaryNodes(root -> left, nodes);
        }
        else if (root -> right) {
            nodes.emplace_back(root -> data);
            getLeftBoundaryNodes(root -> right, nodes);
        }
    }

    void getRightBoundaryNodes(Node *root, vector<int> &nodes) {

        if (!root)
            return;

        if (root -> right) {
            getRightBoundaryNodes(root -> right, nodes);
            nodes.emplace_back(root -> data);
        }
        else if (root -> left) {
            getRightBoundaryNodes(root -> left, nodes);
            nodes.emplace_back(root -> data);
        }
    }

    void getLeafNodes(Node *root, vector<int> &nodes) {

        if (!root)
            return;

        getLeafNodes(root -> left, nodes);

        if (!root -> left && !root -> right)
            nodes.emplace_back(root -> data);

        getLeafNodes(root -> right, nodes);
    }

    vector <int> printBoundary(Node *root)
    {
        if (!root)
            return vector<int> {};

        vector<int> nodes;
        nodes.emplace_back(root -> data);

        getLeftBoundaryNodes(root -> left, nodes);
        getLeafNodes(root -> left, nodes);
        getLeafNodes(root -> right, nodes);
        getRightBoundaryNodes(root -> right, nodes);

        return nodes;
    }
};
// T.C. - O(n), n is the total number of tree nodes
// S.C. - O(h), h is the height of the tree

// { Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.printBoundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
