/**
 * Title   : Find first repeated character
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/find-first-repeated-character/0
 **/

#include<bits/stdc++.h>
using namespace std;

void printFirstRepeatedCharacter(string s) {

    unordered_map<char, int> hm;

    for (int i = 0; s[i]; ++i) {

        ++hm[s[i]];

        if (hm[s[i]] == 2) {
            cout << s[i];
            return;
        }
    }

    cout << -1;
}

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);

        printFirstRepeatedCharacter(s);
        cout << '\n';
    }

    return 0;
}
