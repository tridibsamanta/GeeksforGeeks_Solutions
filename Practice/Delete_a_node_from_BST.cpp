/**
 * Title   : Delete a node from BST
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1
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



struct Node* deleteNode(struct Node* root, int key);

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

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
    string s;
    getline(cin, s);
    Node* root1 = buildTree(s);
    getline(cin, s);
    int k = stoi(s);
    root1  = deleteNode(root1, k);
    vector<int> v;
    inorder(root1, v);
    for(auto i:v)
        cout << i << " ";
    cout << endl;
   }
   return 0;
}// } Driver Code Ends
/* The structure of a BST Node is as follows:
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/

Node* FindMin(Node* root) {
    while(root->left != NULL)
        root = root->left;
    return root;
}

Node *deleteNode(Node *root,  int x)
{
    if(root == NULL)
        return root;
    //Node to be deleted is less than root, will be present in left subtree
    else if(x < root->data)
        root->left = deleteNode(root->left, x);
    //Node to be deleted is greater than root, will be present in right subtree
    else if(x > root->data)
        root->right = deleteNode(root->right, x);
    //Node to be deleted is found
    else {
        //Node has no child nodes
        if(root->left == NULL && root->right == NULL) {
            //Deallocate space
            delete root;
            root = NULL;
        }
        //Node has only one child node
        else if(root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        //Node has 2 child nodes
        else {
            Node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}
