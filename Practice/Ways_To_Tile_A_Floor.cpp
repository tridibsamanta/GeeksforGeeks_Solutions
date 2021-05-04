/**
 * Title   : Ways To Tile A Floor
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/ways-to-tile-a-floor5836/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    #define MAXN 100005
    #define MOD 1000000007
    #define ll long long

    int dp[MAXN];

    long long numberOfWays(long long N) {

        dp[1] = 1, dp[2] = 2;

        for (int i = 3; i <= N; ++i) {
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
        }

        return dp[N];
    }
};

// T.C. - O(n)
// S.C. - O(1)

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;

        cin>>N;

        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
}  // } Driver Code Ends
