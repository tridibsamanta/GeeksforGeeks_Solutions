/**
 * Title   : Sum of Query II
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/sum-of-query-ii5310/1
 **/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> prefSum;

    void precompute(int arr[], int n) {
        prefSum.resize(n+1, 0);

        for (int i = 1; i <= n; ++i) {
            prefSum[i] = prefSum[i - 1] + arr[i - 1];
        }
    }

    vector<int> querySum(int n, int arr[], int q, int queries[]) {

        precompute(arr, n);

        vector<int> rangeSum;

        int i = 0;
        while (i < 2 * q) {
            rangeSum.emplace_back(prefSum[queries[i + 1]] - prefSum[queries[i] - 1]);
            i += 2;
        }

        return rangeSum;
    }
};
// T.C. - O(n) + O(q)
// S.C. - O(n)

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n;
        int arr[n];
        for(int i = 0;i < n;i++)
            cin>>arr[i];
        cin>>q;
        int queries[2*q];
        for(int i = 0;i < 2*q;i += 2)
            cin>>queries[i]>>queries[i+1];

        Solution ob;
        vector<int> ans = ob.querySum(n, arr, q, queries);
        for(int u: ans)
            cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
