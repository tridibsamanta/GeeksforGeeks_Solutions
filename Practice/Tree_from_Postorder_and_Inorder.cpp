/**
 * Title   : Tree from Postorder and Inorder
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
 **/

// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

// Function should construct tree and return
// root of it.  in[] stores inorder traversal
// post[] stores postorder traversal.  n is
// size of these arrays

int searchNode(int in[], int start, int end, int data) {
    for (int i = start; i <= end; ++i)
        if (in[i] == data)
            return i;
    return -1;
}

Node* helpBuildTree(int in[], int post[], int startIdx, int endIdx, int *postIdx) {

    if (startIdx > endIdx)
        return NULL;

    Node *newNode = new Node(post[*postIdx]);
    --(*postIdx);

    if (startIdx == endIdx)
        return newNode;

    int pos = searchNode(in, startIdx, endIdx, newNode -> data);

    newNode -> right = helpBuildTree(in, post, pos + 1, endIdx, postIdx);
    newNode -> left = helpBuildTree(in, post, startIdx, pos - 1, postIdx);

    return newNode;
}

Node *buildTree(int in[], int post[], int n) {
    int postIdx = n - 1;
    return helpBuildTree(in, post, 0, n - 1, &postIdx);
}
