/**
 * Title   : Length of the longest substring
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring/0
 **/

#include<bits/stdc++.h>
using namespace std;

#define ALL_CHARS 256

int findLength(string s) {

   vector<int> lastIndex(ALL_CHARS, -1);
   int maxLength = 0, start = 0;

   for (int j = 0; j < s.size(); ++j) {
        start = max(start, lastIndex[s[j]] + 1);
        maxLength = max(maxLength, j - start + 1);
        lastIndex[s[j]] = j;
   }
   return maxLength;
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        string s;
        cin >> s;

        int res = findLength(s);
        cout << res << '\n';
    }
    return 0;
}
