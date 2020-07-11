/**
 * Title   : Most frequent word in an array of strings
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/most-frequent-word-in-an-array-of-strings/0
 **/

#include<bits/stdc++.h>
using namespace std;

void findMostFrequent(vector<string> str) {

    unordered_map<string, int> mp;
    for (auto i = str.begin(); i != str.end(); ++i)
        ++mp[*i];

    string res = "";
    int maxCount = INT_MIN;

    for (auto i = 0; i < str.size(); ++i) {
        if (mp[str[i]] >= maxCount && mp[str[i]] != -1) {
            res = str[i];
            maxCount = mp[str[i]];
            mp[str[i]] = -1;
        }
    }

    cout << res << '\n';
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        vector<string> str;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            str.emplace_back(s);
        }

        findMostFrequent(str);
    }

	return 0;
}

