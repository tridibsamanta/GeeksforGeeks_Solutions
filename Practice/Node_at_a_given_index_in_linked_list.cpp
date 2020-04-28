/**
 * Title   : Node at a given index in linked list
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/node-at-a-given-index-in-linked-list/1
 **/

// { Driver Code Starts
// C program to find n'th node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list node */
struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }
};

struct node* push(struct node* head, int d)
{

    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));

    new_node->data  = d;
    new_node->next = NULL;

    if (head == NULL) return new_node;

    struct node* h = head;
    while (head->next != NULL) head = head->next;
    head->next = new_node;

    return h;
}

int GetNth(struct node* head, int index);


/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct node *head = NULL;

        cin>>n>>k;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            head = push(head, l);
        }

    printf("%d\n", GetNth(head, k));
    getchar();
    }
    return 0;
}
 // } Driver Code Ends
/* Print he nth node in the linked list Node is defined as
/* Link list node
struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }
};
*/

// Should return data of node at given index. The function may
//  assume that there are at least index+1 nodes in linked list
int GetNth(struct node* head, int index){
  node *temp = NULL;
  for(int i = 0; i < index; ++i) {
      if (temp == NULL)
        temp = head;
      else
        temp = temp->next;
  }
  if (temp == NULL)
    return -1;
else
    return temp->data;
}
