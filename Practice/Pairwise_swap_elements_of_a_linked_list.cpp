/**
 * Title   : Pairwise swap elements of a linked list
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node *pairWiseSwap(Node *head);

void insert(Node **head) {
    int n, i, value;
    Node *temp;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            *head = new Node(value);
            temp = *head;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}

void printList(struct Node *temp) {
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    /* Start with the empty list */
    int t, k, n, value;

    /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
    scanf("%d", &t);

    Node *head = NULL;

    while (t--) {
        head = NULL;
        insert(&head);
        head = pairWiseSwap(head);
        printList(head);
    }
    return (0);
}
// } Driver Code Ends


/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/

/*
//Recursive Approach

Node* pairWiseSwap(struct Node* head) {

    if (head == NULL || head->next == NULL)
        return head;

    struct Node *temp;
    temp = head->next;
    head->next = temp->next;
    temp->next = head;
    head = temp;
    head->next->next = pairWiseSwap(head->next->next);
    return head;

}
*/

//Iterative Approach

Node* pairWiseSwap(struct Node* head) {

    if (head == NULL || head->next == NULL)
        return head;

    struct Node *curr = head, *temp1 = NULL, *temp2 = NULL;

    while (curr != NULL && curr->next != NULL) {

        if (temp1 != NULL)
            temp1->next->next = curr->next;

        temp1 = curr->next;
        curr->next = curr->next->next;
        temp1->next = curr;

        if (temp2 == NULL)
            temp2 = temp1;

        curr = curr->next;
    }

    return temp2;
}
