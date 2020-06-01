/**
 * Title   : Construct Tree from Inorder & Preorder
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/construct-tree-1/1
 **/

// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

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

Node *buildTree(int inorder[], int preorder[], int n);

void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];

		Node *root = buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

int searchNode(int in[], int inStrt, int inEnd, int data) {
    for (int i = inStrt; i <= inEnd; ++i)
        if (in[i] == data)
            return i;
}

Node* buildingTree(int in[],int pre[], int inStrt, int inEnd, int *preIdx)
{
    if (inStrt > inEnd)
        return NULL;

    Node *newNode = new Node(pre[*preIdx]);
    ++*preIdx;

    if (inStrt == inEnd)
        return newNode;

    int inPos = searchNode(in, inStrt, inEnd, newNode -> data);

    newNode -> left = buildingTree(in, pre, inStrt, inPos - 1, preIdx);
    newNode -> right = buildingTree(in, pre, inPos + 1, inEnd, preIdx);

    return newNode;

}

Node* buildTree(int inorder[], int preorder[], int n) {
    int preIdx = 0;
    Node *r = buildingTree(inorder, preorder, 0, n - 1, &preIdx);
    return r;
}
