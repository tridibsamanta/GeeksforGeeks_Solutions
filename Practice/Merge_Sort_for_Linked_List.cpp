/**
 * Title   : Merge Sort for Linked List
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1
 **/

// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends


/* Structure of the linked list node is as
struct Node
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

Node* SortedMerge(Node *head1, Node *head2) {

    Node *result = NULL;

    if (!head1)
        return head2;
    if (!head2)
        return head1;

    if (head1->data <= head2->data) {
        result = head1;
        result->next = SortedMerge(head1->next, head2);
    }
    else {
        result = head2;
        result->next = SortedMerge(head1, head2->next);
    }

    return result;
}

void FrontBackSplit(Node *head, Node **head1, Node **head2) {

    Node *slowPtr = head, *fastPtr = head;

    while (!fastPtr && !(fastPtr->next)) {
        slowPtr = slowPtr-> next;
        fastPtr = fastPtr->next->next;
    }

    *head1 = head;
    *head2 = slowPtr->next;
    slowPtr->next = NULL;
}

/* Function to mergesort the linked list
   It should return head of the modified list  */
Node* mergeSort(Node* head) {

    if (!head || !head->next)
        return head;

    Node *temp = head, *a, *b;

    FrontBackSplit(temp, &a, &b);

    return SortedMerge(mergeSort(a), mergeSort(b));

}


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends
