/**
 * Title   : Reverse words in a given string
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0
 **/

#include<bits/stdc++.h>
using namespace std;

string reverseString(string s, int n) {

    string rev;
    int prev = n, i, j;
    for (i = n - 1; i >= 0; --i) {
        if (s[i] == '.') {
            for (j = i + 1; j < prev; ++j)
                rev += s[j];
            rev += '.';
            prev = i;
        }
    }
    for (int j = i + 1; j < prev; ++j)
        rev += s[j];

    return rev;
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        string s;
        cin >> s;

        int len = s.length();

        string rev = reverseString(s, len);
        cout << rev << '\n';
    }
    return 0;
}
