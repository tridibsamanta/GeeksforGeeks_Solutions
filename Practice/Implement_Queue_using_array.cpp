/**
 * Title   : Implement Queue using array
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/implement-queue-using-array/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
};

class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
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


/*

The structure of the class is
class MyQueue {
private:
    int arr[10001];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */

/* The method push to push element into the queue */
void MyQueue :: push(int x)
{
    if ((rear + 1) == 100005)
        return;
    else if (front == 0 && rear == 0)
        front = rear = 1;
    else
        rear = (rear + 1) % 100005;
    arr[rear] = x;
}

/*The method pop which return the element
  poped out of the queue*/
int MyQueue :: pop()
{
    if (front == 0 && rear == 0)
        return -1;
    else if (front == rear) {
        int data = arr[front];
        front = rear = 0;
        return data;
    }
    else {
        int data = arr[front];
        front = (front + 1) % 100005;
        return data;
    }
}
