/**
 * Title   : Intersection Point in Y Shapped Linked Lists
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1
 **/

// { Driver Code Starts
#include<iostream>
#include<stdio.h>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

int intersectPoint(struct Node* head1, struct Node* head2);

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Driver program to test above function*/
int main()
{
    int T,i,n1, n2, n3,l,k;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;

        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }

        if (tail1 != NULL)
        tail1->next = head3;
        if (tail2 != NULL)
        tail2->next = head3;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    Node *l1 = head1, *l2 = head2;
    int len1 = 0, len2 = 0, diff = 0;
    while (l1 != NULL) {
        ++len1;
        l1 = l1->next;
    }
    while (l2 != NULL) {
        ++len2;
        l2 = l2->next;
    }
    if (len1 < len2) {
        l1 = head2; l2 = head1; diff = len2 - len1;
    }
    else {
        l1 = head1; l2 = head2; diff = len1 - len2;
    }
    for (int i = 0; i < diff; ++i)
        l1 = l1->next;
    while (l1 != NULL && l2 != NULL) {
        if (l1 == l2)
            return l1->data;
        l1 = l1->next;
        l2 = l2->next;
    }
    return -1;
}
