/**
 * Title   : Longest Increasing Subsequence
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];

        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];

        //calling method longestSubsequence()
        cout << longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends


// return length of longest strictly increasing subsequence

int longestSubsequence(int n, int a[]) {

    vector<int> dp;

    dp.emplace_back(a[0]);

    for (int i = 1; i < n; ++i) {

        auto itr = lower_bound(dp.begin(), dp.end(), a[i]);

        if (itr == dp.end())
            dp.emplace_back(a[i]);
        else
            *itr = a[i];
    }

   return dp.size();
}

// T.C. - O(nlogn)
// S.C. - O(n)
