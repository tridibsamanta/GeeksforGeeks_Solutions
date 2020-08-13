/**
 * Title   : Save Ironman
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/save-ironman/0
 **/

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {

    int n = s.length();

    if (n == 1)
        return true;

    int l = 0, r = n - 1;

    while (l < r) {

        while(!isalnum(s[l]) && l < r) {
            ++l;
        }

        while (!isalnum(s[r]) && l < r) {
            --r;
        }

        if (l < r) {
            if (s[l] == s[r]) {
                ++l; --r;
            }
            else
                return false;
        }

    }

    return true;
}

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);

        for (int i = 0; s[i]; ++i)
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = tolower(s[i]);

        if (isPalindrome(s))
            cout << "YES\n";
        else
            cout << "NO\n";

    }

    return 0;
}
