/**
 * Title   : Rotate a Linked List
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node *rotate(struct Node *head, int k);

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;

        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;

        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }

        cin>> k;

        head = rotate(head,k);
        printList(head);
    }
    return 1;
}
// } Driver Code Ends


/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

// This function should rotate list counter-clockwise
// by k and return new head (if changed)

Node* rotate(Node* head, int k) {

    Node *head_ref = head, *curr = head, *prev = NULL;

    while (k--) {
        prev = curr;
        curr = curr -> next;
    }

    if (curr == NULL)
        return head;

    head = curr;
    prev -> next = NULL;

    while (curr -> next != NULL) {
        curr = curr -> next;
    }

    curr -> next = head_ref;

    return head;
}
