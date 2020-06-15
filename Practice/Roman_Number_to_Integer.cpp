/**
 * Title   : Roman Number to Integer
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/roman-number-to-integer/0
 **/

#include<bits/stdc++.h>
using namespace std;

int values(char r) {
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;

    return -1;
}


int romanToInteger(string r) {

    int num = 0;

    for (int i = 0; r[i]; ++i) {

        int curr = values(r[i]);

        if (i + 1 < r.length()) {

            int next = values(r[i + 1]);

            if (curr >= next)
                num += curr;
            else {
                num += next - curr;
                ++i;
            }
        }
        else
            num += curr;
    }

    return num;
}

int main() {

    int t;
    cin >> t;
    while(t--) {

        string r;
        cin >> r;

        int res = romanToInteger(r);
        cout << res << '\n';
    }

    return 0;
}
