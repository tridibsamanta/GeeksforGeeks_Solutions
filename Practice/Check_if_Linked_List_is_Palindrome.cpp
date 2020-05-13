/**
 * Title   : Check if Linked List is Palindrome
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
 **/

// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
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


bool isPalindrome(Node *head);
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
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

// } Driver Code Ends


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
/*You are required to complete this method */

bool checkPalindrome(Node *list1, Node *list2) {
    Node *temp1 = list1, *temp2 = list2;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data == temp2->data) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
            return false;
    }
    return true;
}

void reverseList(Node **head) {
    Node *prev = NULL, *current = *head, *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    Node *slowPtr = head, *prev_slowPtr = head, *fastPtr = head;

    while (fastPtr != NULL && fastPtr->next != NULL) {
        fastPtr = fastPtr->next->next;
        prev_slowPtr = slowPtr;
        slowPtr = slowPtr->next;
    }

    Node *middleNode = NULL, *head2 = NULL;

    if (fastPtr != NULL) {
        middleNode = slowPtr;
        slowPtr = slowPtr->next;
    }

    head2 = slowPtr;
    prev_slowPtr->next = NULL;

    reverseList(&head2);

    bool check;
    check = checkPalindrome(head, head2);

    reverseList(&head2);

    if (middleNode != NULL) {
        prev_slowPtr->next = middleNode;
        middleNode->next = head2;
    }
    else
        prev_slowPtr->next = head2;

    return check;
}

