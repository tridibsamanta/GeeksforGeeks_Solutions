/**
 * Title   : Inorder Successor in BST
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
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

Node* search(Node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
       return root;

    // Key is greater than root's key
    if (root->data < key)
       return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

Node * inOrderSuccessor(Node *, Node* );

int main()
{
    int t;
    cin>>t;
    getchar();

    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);

        int k;
        cin>>k;
        getchar();

        Node* kNode = search( head, k );
        Node* suc = inOrderSuccessor(head, kNode);

        if( suc == NULL ) cout<< "-1";
        else cout<< suc->data;
        cout << endl;
    }

    return 1;
}// } Driver Code Ends
/*The structure of Node
struct Node {
int data;
Node * right, * left;
};*/

Node* SearchNode(Node* root, Node* target) {
    if(root == NULL) return NULL;
    else if(target->data == root->data) return root;
    else if(target->data < root->data) return SearchNode(root->left, target);
    else return SearchNode(root->right, target);
}

/* The below function should return the node which is
inorder successor of given node x. */
Node * inOrderSuccessor(Node *root, Node *x)
{
    Node* current = SearchNode(root, x);
    if(current == NULL) return NULL;
    if(current->right != NULL) {
        Node* temp = current->right;
        while(temp->left != NULL)
            temp = temp->left;
        return temp;
    }
    else {
        Node* successor = NULL;
        Node* ancestor = root;
        while(ancestor != current) {
            if(current->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}
