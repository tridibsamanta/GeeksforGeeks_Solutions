/**
 * Title   : Pairwise Consecutive Elements
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/pairwise-consecutive-elements/1
 **/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

bool pairWiseConsecutive(stack<int> s);

// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        stack<int> s;
        int n, tmp;
        cin>>n;
        while(n--){
            cin>>tmp;
	        s.push(tmp);
	    }
	    if (pairWiseConsecutive(s))cout << "Yes" << endl;
	    else cout << "No" << endl;
	    /*while (s.empty() == false)
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout<<endl;*/
    }
	return 0;
}
// } Driver Code Ends


//User function Template for C++

// your task is to complete the function
// function should return true/false or 1/0
bool pairWiseConsecutive(stack<int> s)
{
    bool res = true;

    stack<int> aux;
    while (!s.empty()) {
        aux.push(s.top());
        s.pop();
    }

    while (aux.size() > 1) {

        int temp1 = aux.top();
        aux.pop();
        int temp2 = aux.top();
        aux.pop();

        if (abs(temp1 - temp2) != 1)
            return false;

        s.push(temp1);
        s.push(temp2);
    }

    if (aux.size() == 1)
        s.push(aux.top());

    return res;
}
