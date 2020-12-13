/**
 * Title   : Check Mirror in N-ary tree
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/cutted-segments1642/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z);

int main() {

    //taking testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking length of line segment
        int n;
        cin >> n;

        //taking types of segments
        int x, y, z;
        cin >> x >> y >> z;

        //calling function maximizeTheCuts()
        cout << maximizeTheCuts(n, x, y, z) << endl;

    }

    return 0;
}// } Driver Code Ends

int dp[10005];

/* Top-Down Approach */

/*
int maximizeTheCutsUtil(int n, int x, int y, int z) {

    if (n == 0)
        return 0;

    if (n < 0)
        return INT_MIN;

    if (dp[n] != -1)
        return dp[n];

    int cuts_x = 1 + maximizeTheCutsUtil(n - x, x, y, z);
    int cuts_y = 1 + maximizeTheCutsUtil(n - y, x, y, z);
    int cuts_z = 1 + maximizeTheCutsUtil(n - z, x, y, z);

    return dp[n] = max(cuts_x, max(cuts_y, cuts_z));
}

int maximizeTheCuts(int n, int x, int y, int z) {

    memset(dp, -1, sizeof(dp));

    int cuts = maximizeTheCutsUtil(n, x, y, z);

    return (cuts < 0) ? 0 : cuts;
}
*/

/* Bottom-Up Approach */

int maximizeTheCuts(int n, int x, int y, int z) {

    memset(dp, -1, sizeof(dp));

    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {

        if (i - x >= 0) {
            dp[i] = max(dp[i], dp[i - x]);
        }

        if (i - y >= 0) {
            dp[i] = max(dp[i], dp[i - y]);
        }

        if (i - z >= 0) {
            dp[i] = max(dp[i], dp[i - z]);
        }

        if (dp[i] != -1)
            ++dp[i];
    }

    return max(dp[n], 0);
}
