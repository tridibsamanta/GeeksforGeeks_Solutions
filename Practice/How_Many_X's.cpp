/**
 * Title   : How Many X's?
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/how-many-xs/0/
 **/

#include<bits/stdc++.h>
using namespace std;

int getOccurenceCount(int d, int lb, int ub) {

    int res = 0;
    for (int i = lb + 1; i < ub; ++i) {

        string num = to_string(i);

        for (int i = 0; num[i]; ++i)
            if (num[i] - '0' == d)
                ++res;
        }

    return res;
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        int d;
        cin >> d;

        int lb, ub;
        cin >> lb >> ub;

        int res = getOccurenceCount(d, lb, ub);
        cout << res << '\n';

    }

    return 0;
}
