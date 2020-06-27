/**
 * Title   : Is Binary Tree Heap
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

bool isHeap(struct Node * tree);

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }

     cout << isHeap(root)<< endl;
  }
  return 0;
}

// } Driver Code Ends


/*
 A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

int countNodes(Node* root) {
    if (root == NULL)
        return 0;
    return (1 + countNodes(root->left) + countNodes(root->right));
}

bool isCompleteUtil (Node* root, int index, int node_count) {

    if (!root)
        return true;

    if (index >= node_count)
        return false;

    return (isCompleteUtil(root -> left, 2 * index + 1, node_count) &&
            isCompleteUtil(root -> right, 2 * index + 2, node_count));
}

bool isHeapUtil(Node* root) {
    if (!root -> left && !root -> right)
        return true;

    if (!root -> right)
        return (root -> data >= root -> left -> data);
    else {
        if (root -> data >= root -> left -> data && root -> data >= root -> right -> data)
            return ((isHeapUtil(root -> left)) && (isHeapUtil(root -> right)));
        else
            return false;
    }
}

/*You are required to complete this method */
bool isHeap(Node *tree) {
    int index = 0, node_count = countNodes(tree);
    if (isCompleteUtil(tree, index, node_count) && isHeapUtil(tree))
        return true;
    return false;
}
