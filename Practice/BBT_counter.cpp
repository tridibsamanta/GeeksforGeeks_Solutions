/**
 * Title   : BBT counter
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/bbt-counter4914/1
 **/

// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// User function Template for C++
class Solution {
public:
    long long dp[1003];
    const int MOD = 1e9 + 7;

    long long int countBT(int h) {

        dp[0] = dp[1] = 1;

        for (int i = 2; i <= h; ++i) {
            dp[i] = (dp[i - 1] * ((2 * dp[i - 2]) % MOD + dp[i - 1]) % MOD) % MOD;
        }

        return dp[h];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout << ob.countBT(h) << endl;
    }
    return 0;
}
// } Driver Code Ends
