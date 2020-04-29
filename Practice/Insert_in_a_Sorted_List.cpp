/**
 * Title   : Insert in a Sorted List
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/insert-in-a-sorted-list/1
 **/

// { Driver Code Starts
#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;

    node(int x) {
        data = x;
        next = NULL;
    }
};

void sortedInsert(struct node **head_ref, int data);

node *last = nullptr;

void append(struct node **headRef, int newData) {
    struct node *new_node = new node(newData);

    if (*headRef == NULL) {
        *headRef = new_node;
        last = *headRef;
        return;
    }
    //    while (last->next != NULL)last = last->next;
    last->next = new_node;
    last = last->next;
}
void printList(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

/* Drier program to test count function*/
int main() {
    int test;
    cin >> test;
    while (test--) {
        struct node *head = NULL;
        int n, k;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> k;
            append(&head, k);
        }
        cin >> k;
        sortedInsert(&head, k);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends
/*
structure of the node of the list is as
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
void sortedInsert(struct node** head_ref, int data) {
    node* newNode = new node(data);
    newNode->data = data;
    newNode->next = NULL;
    if (*head_ref == NULL || newNode->data <= (*head_ref)->data) {
        newNode->next = *head_ref;
        *head_ref = newNode;
        return;
    }
    node *current = *head_ref, *temp = *head_ref;
    while (current != NULL && current->data < newNode->data) {
        temp = current;
        current = current->next;
    }
    newNode->next = current;
    temp->next = newNode;
}
