/**
 * Title   : Edit Distance
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/edit-distance3702/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<vector<int> > dp;

    int editDistanceUtil(int a, int b, string x, string y) {

        if (a == 0 && b == 0)
            return 0;

        if (a == 0)
            return b;
        if (b == 0)
            return a;

        if (dp[a][b] != -1)
            return dp[a][b];

        int cost;
        (x[a - 1] == y[b - 1]) ? cost = 0 : cost = 1;

        return dp[a][b] = min(editDistanceUtil(a, b - 1, x, y) + 1,
                            min(editDistanceUtil(a - 1, b, x, y) + 1,
                                editDistanceUtil(a - 1, b - 1, x, y) + cost));
    }

    int editDistance(string s, string t) {

        int a = s.length(), b = t.length();
        dp.resize(a+1, vector<int> (b+1, -1));
        return editDistanceUtil(a, b, s, t);
    }
};

// T.C. - O(s.length() * t.length())
// S.C. - O(s.length() * t.length())

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
