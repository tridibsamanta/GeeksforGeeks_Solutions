/**
 * Title   : Root to leaf path sum
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/root-to-leaf-path-sum/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

bool hasPathSum(Node *, int);

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int sum;
        scanf("%d ", &sum);
        cout << hasPathSum(root, sum) << "\n";
    }
    return 0;
}
// } Driver Code Ends


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */
bool hasPathSum(Node *node, int sum) {
    if (node == NULL) {
        if (sum == 0)
            return true;
        else
            return false;
    }

    else {

    bool ans = 0;

    int currSum = sum - (node -> data);

    if (currSum == 0 && node -> left == NULL && node -> right == NULL)
        return true;

    if (node -> left != NULL)
        ans = ans || hasPathSum(node -> left, currSum);

    if (node -> right != NULL)
        ans = ans || hasPathSum(node -> right, currSum);

    return ans;
    }
}
