/**
 * Title   : Implement Queue using Linked List
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/implement-queue-using-linked-list/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};



int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        MyQueue *sq = new MyQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }
    }
// } Driver Code Ends


/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

/* The method push to push element into the queue*/
void MyQueue:: push(int x)
{
    QueueNode *temp = new QueueNode(x);

    if (temp == NULL)
        return;

    if (rear == NULL) {
        front = rear = temp;
        return;
    }

    rear -> next = temp;
    rear = temp;
}

/*The method pop which return the element
  poped out of the queue*/
int MyQueue :: pop()
{
    if (front == NULL)
     return -1;

    QueueNode *temp = front;
    front = front -> next;

    if (front == NULL)
        rear = NULL;

    int element = temp -> data;
    delete (temp);

    return element;
}
