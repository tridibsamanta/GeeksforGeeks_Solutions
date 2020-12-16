/**
 * Title   : Count ways to reach the n'th stair
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

long long countWays(int);

int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking stair count
        int m;
        cin >> m;

        cout << countWays(m) << endl; // Print the output from our pre computed array
    }
    return 0;
}
// } Driver Code Ends


int dp[100005];

// Top-Down Approach (Memoization)
/*
long long countWaysUtil(int m) {

    if (m <= 2)
        return m;

    if (dp[m] != -1)
        return dp[m];

    return dp[m] = (countWaysUtil(m - 1) + countWaysUtil(m - 2)) % mod;
}

long long countWays(int m) {
    memset(dp, -1, sizeof(dp));
    return countWaysUtil(m);
}
*/

// Bottom-Up Approach (Tabulation)

long long countWays(int m) {

    for (int i = 0; i <= 2; ++i)
        dp[i] = i;

    for (int i = 3; i <= m; ++i)
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;

    return dp[m];
}
