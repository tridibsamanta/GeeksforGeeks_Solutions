/**
 * Title   : Reverse a linked list
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
 **/

// { Driver Code Starts
//Initial Template for C++

// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
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

void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node* new_node = new Node(new_data);

    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
struct Node *reverseList(struct Node *head);

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T,n,l;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
       head = reverseList(head);

       printList(head);

       cout << endl;
    }
    return 0;
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
// Should reverse list and return new head.

// Iterative Approach
/*
Node* reverseList(Node *head)
{
  Node *next = NULL, *temp = NULL;
  while(head) {
      next = head->next;
      head->next = temp;
      temp = head;
      head = next;
  }
  return temp;
}
*/

// Recursive Approach
Node* reverseList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *secondElement = head->next;
    head->next = NULL;
    Node *reverseRest = reverseList(secondElement);
    secondElement->next = head;
    return reverseRest;
}
