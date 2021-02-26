/**
 * Title   : Maximum Profit
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/maximum-profit4657/1
 **/

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dp[201][501];

    int maxProfit(int K, int N, int A[]) {

        for (int i = 0; i <= K; ++i)
            dp[i][0] = 0;
        for (int i = 0; i <= N; ++i)
            dp[0][i] = 0;

        for (int i = 1; i <= K; ++i) {

            int maxDiff = -A[0];

            for (int j = 1; j < N; ++j) {

                dp[i][j] = max(dp[i][j - 1], A[j] + maxDiff);
                maxDiff = max(maxDiff, dp[i-1][j] - A[j]);
            }
        }

        return dp[K][N-1];
    }
};

// T.C. - O(K * N)
// S.C. - O(K * N)

/*
class Solution {
  public:
    int dp[201][501];

    int maxProfit(int K, int N, int A[]) {

        for (int i = 0; i <= K; ++i)
            dp[i][0] = 0;
        for (int i = 0; i <= N; ++i)
            dp[0][i] = 0;

        for (int i = 1; i <= K; ++i) {

            for (int j = 1; j < N; ++j) {

                int maxVal = 0;

                for (int m = 0; m < j; ++m)
                     maxVal = max(maxVal, A[j] - A[m] + dp[i-1][m]);


                dp[i][j] = max(dp[i][j-1], maxVal);
            }
        }

        return dp[K][N-1];
    }
};
*/

// T.C. - O(K * N^2)
// S.C. - O(K * N)

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends
