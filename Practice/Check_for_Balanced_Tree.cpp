/**
 * Title   : Check for Balanced Tree
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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

bool isBalanced(Node *root);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        cout << isBalanced(root) << endl;
    }
    return 1;
}// } Driver Code Ends


/* A binary tree node structure

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

// This function should return tree if passed  tree
// is balanced, else false.

int isBalancedUtil(Node *root) {
    if (!root)
        return 0;
    int lh = isBalancedUtil(root -> left);
    if (lh == -1)
        return -1;
    int rh = isBalancedUtil(root -> right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return max(lh, rh) + 1;
}

bool isBalanced(Node *root) {
    return (isBalancedUtil(root) == -1) ? false : true;
}

/* ~~~ Approach 2 ~~~

int getHeight(Node *root) {
    if (!root)
        return 0;
    return max(getHeight(root -> left), getHeight(root -> right)) + 1;
}

bool isBalanced(Node *root)
{
    if (!root)
        return true;

    int lh = getHeight(root -> left);
    int rh = getHeight(root -> right);

    if (abs(lh - rh) <= 1 && isBalanced(root -> left) && isBalanced(root -> right))
        return true;

    return false;
}
*/
