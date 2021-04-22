/**
 * Title   : String Subsequence
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1
 **/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

// Bottom-Up (Tabulation) Approach

class Solution{
private:
    int dp[505][505];

public:
    int countWays(string a, string b){

        int m = a.length(), n = b.length();

        for (int i = 1; i <= n; ++i)
            dp[0][i] = 0;
        for (int i = 0; i <= m; ++i)
            dp[i][0] = 1;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {

                if (a[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[m][n];
    }
};

// T.C. - O(m*n)
// S.C. - O(m*n)

// Top-Down (Memoization) Approach
/*
class Solution{
private:
    int dp[505][505];

public:
    int countWaysUtil(string& a, string& b, int m, int n) {

        if (n == 0)
        return 1;

        if (m == 0)
        return 0;

        if (dp[m][n] != -1)
            return dp[m][n];

        if (a[m-1] == b[n-1]) {
            return dp[m][n] = countWaysUtil(a, b, m-1, n-1) + countWaysUtil(a, b, m-1, n);
        }
        else {
            return dp[m][n] = countWaysUtil(a, b, m-1, n);
        }
    }

    int countWays(string S1, string S2){
        memset(dp, -1, sizeof(dp));
        return countWaysUtil(S1, S2, S1.length(), S2.length());
    }
};
*/

// T.C. - O(m*n)
// S.C. - O(m*n)

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends
