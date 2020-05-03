/**
 * Title   : Finding middle element in a linked list
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1
 **/

// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);

    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}


/* Function to get the middle of the linked list*/
int getMiddle(struct Node *head);

/* Driver program to test above function*/
int main()
{
  int T,i,n,l;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }

    printf("%d\n", getMiddle(head));
    }
    return 0;
}
// } Driver Code Ends

/* Link list Node
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */

/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
    if (head == NULL)
        return -1;
    Node *slowPtr = head, *fastPtr = head;
    while (fastPtr != NULL && fastPtr->next != NULL) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    return slowPtr->data;
}
