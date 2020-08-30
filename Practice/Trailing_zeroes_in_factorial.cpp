/**
 * Title   : Trailing zeroes in factorial
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/trailing-zeroes-in-factorial/0
 **/

#include<bits/stdc++.h>
using namespace std;

int findTrailingZeros(int n) {

    int i = 5, count = 0;

    while (n / i >= 1) {

        count += n / i;
        i *= 5;

    }

    return count;
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        int res = findTrailingZeros(n);
        cout << res << '\n';

    }

    return  0;

}
