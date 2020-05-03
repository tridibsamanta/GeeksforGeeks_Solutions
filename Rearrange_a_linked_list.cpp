/**
 * Title   : Rearrange a linked list
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/rearrange-a-linked-list/1
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


// Rearranges given linked list such that all even
// positioned Nodes are before odd positioned.
// Returns new head of linked List.
Node *rearrangeEvenOdd(Node *head);

/* Driver program to test above function*/
int main()
{
    int T,i,n,l;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;

            if (head == NULL)
            {
                head = temp = new Node(l);

            }
            else
            {  temp->next = new Node(l);
               temp = temp->next;
            }
        }

        head = rearrangeEvenOdd(head);
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}
// } Driver Code Ends

/* Node structure

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

// Should rearrange given linked list such that all even
// positioned Nodes are before odd positioned.
// Returns new head of linked List.
Node *rearrangeEvenOdd(Node *head)
{
   if (head == NULL)
       return NULL;

   Node *oddPtr = head, *evenPtr = head->next, *evenHead = evenPtr;
   while (evenPtr != NULL && evenPtr->next != NULL) {
       oddPtr->next = evenPtr->next;
       oddPtr = oddPtr->next;
       evenPtr->next = oddPtr->next;
       evenPtr = evenPtr->next;
   }
   oddPtr->next = evenHead;
   return head;
}
