/**
 * Title   : Segregate even and odd nodes in a Linked List
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list/0
 **/

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void segregateEvenOdd(struct Node **head_ref)
{
    Node *evenPtr = NULL, *evenHead = NULL, *oddPtr = NULL, *oddHead = NULL, *check = *head_ref;

    while (check != NULL) {

        if ((check->data % 2) != 0) {
            if (oddHead == NULL) {
                oddHead = check;
                oddPtr = oddHead;
            }
            else {
                oddPtr->next = check;
                oddPtr = oddPtr->next;
            }
        }
        else {
            if (evenHead == NULL) {
                evenHead = check;
                evenPtr = evenHead;
            }
            else {
                evenPtr->next = check;
                evenPtr = evenPtr->next;
            }
        }
        check = check->next;
    }

    if (oddHead == NULL || evenHead == NULL)
        return;

    evenPtr->next = oddHead;
    oddPtr->next = NULL;
    *head_ref = evenHead;
}

void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct Node *temp = *head_ref;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--) {

        struct Node *head = NULL;

        int N, val;
        cin >> N;

        for (int i = 0; i < N; ++i) {
            cin >> val;
            push(&head, val);
        }

        segregateEvenOdd(&head);
        printList(head);
        cout << "\n";

        }

    return 0;
}
