/**
 * Title   : IPL 2021 - Final
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/3b47f0ad00f953dd514235ddec54e39fdc297dda/1
 **/

// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {

        stack<int> idx;
        idx.push(-1);

        int maxLen = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                idx.push(i);
            else {
                if (!idx.empty())
                    idx.pop();

                if (!idx.empty())
                    maxLen = max(maxLen, i - idx.top());
                else
                    idx.push(i);
            }
        }

        return maxLen;
    }
};
// T.C. - O(|s|)
// S.C. - O(|s|)

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends
