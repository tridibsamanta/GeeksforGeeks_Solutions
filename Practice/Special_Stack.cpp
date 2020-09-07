/**
 * Title   : Special Stack
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/special-stack/1
 **/

// { Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(int a);
bool isFull(int n);
bool isEmpty();
int pop();
int getMin();
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty()){
		    pop();
		}
		while(!isFull(n)){
			cin>>a;
			push(a);
		}
		cout<<getMin()<<endl;
	}
}// } Driver Code Ends

int minEle;

/*Complete the function(s) below*/
void push(int a)
{
    if (s.empty()) {
        s.push(a);
        minEle = a;
    }
    else {
        if (a < minEle) {
            s.push(2 * a - minEle);
            minEle = a;
        }
        else
            s.push(a);
    }
}

bool isFull(int n)
{
    if (s.size() == n)
        return true;
    else
        return false;
}

bool isEmpty()
{
    if (s.size() == 0)
        return true;
    else
        return false;
}

int pop()
{
    if (s.size() == 0)
        return -1;

    int t = s.top();
    s.pop();

    if (t < minEle) {
        int temp = minEle;
        minEle = 2 * minEle - t;
        return temp;
    }

    return t;
}

int getMin()
{
   return minEle;
}
