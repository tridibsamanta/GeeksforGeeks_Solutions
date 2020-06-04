/**
 * Title     : Check if two Binary Trees are Isomorphic
 * Author    : Tridib Samanta
**/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node (int x) {
        data = x;
        left = right = NULL;
    }
};

Node* InsertNode(Node *root, int data)
{
    if (!root) {
        root = new Node(data);
        return root;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if (temp -> left != NULL)
            q.push(temp -> left);
        else {
            temp -> left = new Node(data);
            return root;
        }

        if (temp -> right != NULL)
            q.push(temp -> right);
        else {
            temp -> right = new Node(data);
            return root;
        }
    }
}

void TraverseLevelOrder(Node *root)
{
    if (!root) {
        cout << "Tree is empty !\n";
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();
        cout << temp -> data << ' ';
        if (temp -> left != NULL)
            q.push(temp -> left);
        if (temp -> right != NULL)
            q.push(temp -> right);
    }
}

bool checkIsomorphic(Node *root1, Node *root2) {

    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    if (root1 -> data != root2 -> data)
        return false;

    return (checkIsomorphic(root1 -> left, root2 -> left) && checkIsomorphic(root1 -> right, root2 -> right)) ||
            (checkIsomorphic(root1 -> left, root2 -> right) && checkIsomorphic(root1 -> right, root2 -> left));
}

int main()
{
    Node *root1 = NULL;

    root1 = InsertNode(root1, 1); root1 = InsertNode(root1, 2); root1 = InsertNode(root1, 3);
    root1 = InsertNode(root1, 4); root1 = InsertNode(root1, 5); root1 = InsertNode(root1, 6);
    root1 = InsertNode(root1, 7);

    cout << "Tree A : ";
    TraverseLevelOrder(root1);
    cout << endl;

    Node *root2 = NULL;

    root2 = InsertNode(root2, 1); root2 = InsertNode(root2, 3); root2 = InsertNode(root2, 2);
    root2 = InsertNode(root2, 7); root2 = InsertNode(root2, 6); root2 = InsertNode(root2, 5);
    root2 = InsertNode(root2, 4);

    cout << "Tree B : ";
    TraverseLevelOrder(root2);
    cout << endl;

    if (checkIsomorphic(root1, root2))
        cout << "Tree A and Tree B are Isomorphic\n";
    else
        cout << "Tree A and Tree B are not Isomorphic\n";

    return 0;
}

/*
 ~ Time Complexity   : O(min(m,n))
 ~ Space Complexity  : O(min(m,n))
   where, 'm' and 'n' are the number of nodes of Tree A and Tree B respectively.
*/

