/**
 * Title   : Find length of Loop
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/find-length-of-loop/1
 **/

// { Driver Code Starts


#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void append(struct Node **tail, int data)
{
	struct Node* new_node = new Node (data);
	(*tail)->next = new_node;
	(*tail) = new_node;
	return;
}

void printList(struct Node *tmp){
    while(tmp){
        cout<<tmp->data<<' ';
        tmp=tmp->next;
    }
    cout<<endl;
}

int countNodesinLoop(struct Node *head);

/* Drier program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, tmp;
        cin>>n;
        struct Node *head = NULL;
        struct Node *tail = NULL;
        struct Node* temp;
        struct Node *s;
        struct Node *t;
        cin>>tmp;
        struct Node* new_node = new Node (tmp);
        head = new_node;
        tail = new_node;
        s=head;
        for(int i=1; i<n; i++){
            cin>>tmp;
            append(&tail, tmp);
        }
        /* Create a loop for testing */
        // srand(time(NULL));
        int c;
        cin>>c;
        if(c>0){
            //c=c-1;
            temp=head;
            t = head;
            while(t->next)t=t->next;
            while(c--)temp=temp->next;
            t->next=temp;
            // s->next=temp;
        }
        //printList(head);
        cout<<countNodesinLoop(head)<<endl;
	}
    return 0;
}// } Driver Code Ends
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
// Your task is to complete the function this function
// function should return the size of the loop
int countNodesinLoop(struct Node *head)
{
     Node *slowPtr = head, *fastPtr = head;
     bool loopExists = false;
     while (slowPtr && fastPtr && fastPtr->next) {
         slowPtr = slowPtr->next;
         fastPtr = fastPtr->next->next;
         if (slowPtr == fastPtr) {
             loopExists = true;
             break;
         }
     }
     int count = 0;
     if (loopExists) {
         fastPtr = fastPtr->next;
         ++count;
         while (fastPtr != slowPtr) {
             fastPtr = fastPtr->next;
             ++count;
         }
     }
     return count;
}
