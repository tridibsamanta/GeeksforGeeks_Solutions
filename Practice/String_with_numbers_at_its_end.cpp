/**
 * Title   : String with numbers at its end
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/string-with-numbers-at-its-end/0
 **/

#include<bits/stdc++.h>
using namespace std;

bool checkEquality(string str) {

    int n = str.length(), num = 0, place = 1, i;

    for (i = n - 1; i >= 0; --i) {

        if (str[i] >= '0' && str[i] <= '9') {
            num += (str[i] - '0') * place;
            place *= 10;

            if (num >= i + 1)
                return false;
        }
        else
            break;
    }

    return (num == ++i);
}

int main() {

    int t;
    cin >> t;

    while (t--) {

        string str;
        cin >> str;

        if (checkEquality(str))
            cout << 1 << '\n';
        else
            cout << 0 << '\n';

    }

    return 0;
}
