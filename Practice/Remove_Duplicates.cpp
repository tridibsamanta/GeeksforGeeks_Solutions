/**
 * Title   : Remove Duplicates
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/remove-duplicates/0
 **/

#include<bits/stdc++.h>
using namespace std;

void removeDuplicates(string s) {

    unordered_map<char, bool> check;
    int idx = 0;
    for (int i = 0; s[i]; ++i) {
        if (!check[s[i]]) {
            s[idx++] = s[i];
            check[s[i]] = true;
        }
    }
    s[idx] = '\0';
    for (int i = 0; s[i]; ++i)
        cout << s[i];
}

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);

        removeDuplicates(s);
        cout << '\n';

    }

    return 0;
}
