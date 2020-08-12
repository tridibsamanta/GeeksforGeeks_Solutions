/**
 * Title   : Vertical Traversal of Binary Tree
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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

vector <int> verticalOrder(Node *root);

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

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
    	Node* root = buildTree(s);

    	vector <int> res = verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}


// } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// root: root node of the tree
vector<int> verticalOrder(Node *root) {

    vector<int> res;

    if (!root)
        return res;

    map<int, vector<int> > hm;

    queue<pair<Node*, int> > q;
    q.push(make_pair(root, 0));

    while (!q.empty()) {

        pair<Node*, int> temp;
        temp = q.front();
        q.pop();

        Node *curr = temp.first;
        int col = temp.second;

        hm[col].emplace_back(curr -> data);

        if (curr -> left)
            q.push(make_pair(curr -> left, col - 1));
        if (curr -> right)
            q.push(make_pair(curr -> right, col + 1));
    }

    map<int, vector<int> > :: iterator it;
    for (it = hm.begin(); it != hm.end(); ++it) {
        for (int i = 0; i < it->second.size(); ++i)
            res.emplace_back(it->second[i]);
    }

    return res;
}
