/**
 * Title   : Merge K sorted linked lists
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
 **/

// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;

	Node(int x){
	    data = x;
	    next = NULL;
	}

};

Node* mergeKLists(Node* arr[], int N);

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}

   		Node *res = mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
// } Driver Code Ends


/*Linked list Node structure

struct Node
{
	int data;
	Node* next;

	Node(int x){
	    data = x;
	    next = NULL;
	}

};
*/

/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */

struct compare {
    bool operator()(const Node* list1, const Node* list2) {
        return list1 -> data > list2 -> data;
    }
};

Node* mergeKLists(Node *arr[], int k) {

    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for (int i = 0; i < k; ++i) {
        if (arr[i])
            minHeap.push(arr[i]);
    }

    Node *dummy = new Node(0);
    Node *tail = dummy;

    while (!minHeap.empty()) {

        Node *top = minHeap.top();
        minHeap.pop();

        if (top -> next)
            minHeap.push(top -> next);

        tail -> next = top;
        tail = tail -> next;
    }

    return dummy -> next;
}
