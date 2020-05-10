/**
 * Title   : Reorder List
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/reorder-list/1
 **/

// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
// } Driver Code Ends


/* Following is the Linked list node structure */

/*
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

void reverseList(Node **head2) {
    Node *prev = NULL, *curr = *head2, *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head2 = prev;
}

void reorderList(Node* head) {

    // 1. Find the middle of the list using the slow and fast pointer approach
    Node *slowPtr = head, *fastPtr = head;
    while (fastPtr != NULL && fastPtr->next != NULL) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    // 2. Split the linked list into two halves
    Node *head1 = head;
    Node *head2 = slowPtr->next;
    slowPtr-> next = NULL;

    // 3. Reverse the second half
    reverseList(&head2);

    // 4. Form the new list by taking one node alternately from list 1 & list 2
    Node *temp = new Node(0);
    head = temp;
    Node *curr = head;

    while (head1 != NULL || head2 != NULL) {
        if (head1 != NULL) {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }
        if (head2!= NULL) {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }

    head = head->next;
    delete temp;

}
