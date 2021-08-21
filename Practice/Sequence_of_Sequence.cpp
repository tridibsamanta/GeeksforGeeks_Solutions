/**
 * Title   : Sequence of Sequence
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/sequence-of-sequence1155/1
 **/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

/* Recursive Approach (Without memoization)*/
/*
class Solution{
public:
    int numberSequenceUtil(int m, int n) {

        if (m < n)
            return 0;

        if (n == 0)
            return 1;

        return numberSequenceUtil(m / 2, n - 1) +
                numberSequenceUtil(m - 1, n);
    }

    int numberSequence(int m, int n){
        return numberSequenceUtil(m, n);
    }
};
// T.C. - O(m * n)
// S.C. - O(1)
*/

/* Top-Down Approach (Memoization) */
/*
class Solution{
public:
    vector<vector<int>> dp;

    int numberSequenceUtil(int m, int n) {

        if (m < n)
            return 0;

        if (n == 0)
            return 1;

        if (dp[m][n] != -1)
            return dp[m][n];

        return dp[m][n] = numberSequenceUtil(m / 2, n - 1) +
                            numberSequenceUtil(m - 1, n);
    }

    int numberSequence(int m, int n){
        dp.clear();
        dp.resize(m + 1, vector<int> (n + 1, -1));
        return numberSequenceUtil(m, n);
    }
};
// T.C. - O(m * n)
// S.C. - O(m * n)
*/

/* Bottom-Up Approach (Tabulation) */

class Solution{
public:
    vector<vector<int>> dp;

    int numberSequence(int m, int n){
        dp.clear();
        dp.resize(m + 1, vector<int> (n + 1, -1));

        // No need to initialize the first row / column
        // i.e. dp[i][j] = 0, when i = 0 or j = 0

        for (int i = 1; i <= m; ++i)
            dp[i][1] = i;

        for (int j = 2; j <= n; ++j)
            dp[1][j] = 0;

        for (int i = 2; i <= m; ++i) {
            for (int j = 2; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i / 2][j - 1];
            }
        }

        return dp[m][n];
    }
};
// T.C. - O(m * n)
// S.C. - O(m * n)

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;

        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends
