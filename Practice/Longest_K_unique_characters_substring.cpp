/**
 * Title   : Longest K unique characters substring
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring/0
 **/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {

    	string s;
    	cin >> s;

        int k;
        cin >> k;

        int pos = 0, maxCount = 0;

        unordered_map<char, int> ump;

        for (int i = 0; s[i]; ++i) {

            ++ump[s[i]];

            if (ump.size() > k) {

                while (pos < i) {

                    if (--ump[s[pos]] == 0) {
                        ump.erase(s[pos]);
                        ++pos;
                        break;
                    }

                    ++pos;
                }
            }

            if (ump.size() == k)
                maxCount = max(maxCount, i - pos + 1);
        }

        if (maxCount == 0)
            cout << -1 << '\n';
        else
            cout << maxCount << '\n';
    }

    return 0;
}
