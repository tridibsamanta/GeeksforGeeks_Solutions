/**
 * Title   : Repeated Character
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/repeated-character/0
 **/

#include<bits/stdc++.h>
using namespace std;

void printFirstRepeatedCharacter(string s) {

    map<char, int> freq;

    for (int i = 0; s[i]; ++i)
        ++freq[s[i]];

    for (int i = 0; s[i]; ++i) {
        if (freq[s[i]] > 1) {
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
