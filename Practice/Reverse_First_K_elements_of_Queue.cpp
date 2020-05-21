/**
 * Title   : Reverse First K elements of Queue
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
 **/

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long
queue<ll> modifyQueue(queue<ll> q, int k);
int main(){
    ll t;
    cin>>t;
    while(t-->0){
        ll n,k;
        cin>>n>>k;
        queue<ll> q;
        while(n-->0){
            ll a;
            cin>>a;
            q.push(a);
        }
        queue<ll> ans=modifyQueue(q,k);
        while(!ans.empty()){
            int a=ans.front();
            ans.pop();
            cout<<a<<" ";
        }
        cout<<endl;
    }
}// } Driver Code Ends


//User function Template for C++

queue<ll> modifyQueue(queue<ll> q, int k)
{
    if (q.empty() || (q.size() < k) || ( k <= 0))
        return q;

    stack<ll> aux;

    for (int i = 0; i < k; ++i) {
        aux.push(q.front());
        q.pop();
    }

    while (!aux.empty()) {
        q.push(aux.top());
        aux.pop();
    }

    for (int i = 0; i < (q.size() - k); ++i) {
        q.push(q.front());
        q.pop();
    }

    return q;
}
