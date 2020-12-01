/**
 * Title   : Reverse each word in a given string
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/reverse-each-word-in-a-given-string/0
 **/

#include<bits/stdc++.h>
using namespace std;

string reverseWords(string str) {

    string res = "";

    int currStart = 0;

    for (int i = 0; str[i]; ++i) {

        if (str[i+1] == '.' || str[i+1] == '\0') {

            for (int j = i; j >= currStart; --j)
                res += str[j];

        }

        if (str[i] == '.') {
            res += '.';
            currStart = i+1;
        }

    }

    return res;
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;

        string rev_str = reverseWords(str);
        cout << rev_str << '\n';

    }

    return 0;
}
