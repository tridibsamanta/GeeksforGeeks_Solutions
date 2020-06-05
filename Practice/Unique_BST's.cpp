/**
 * Title   : Unique BST's
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/unique-bsts/0
 **/

#include<bits/stdc++.h>
using namespace std;

#define ul unsigned long

ul getBstCount(int n) {

    ul catalan[n + 1];

    catalan[0] = 1;
    catalan[1] = 1;

    for (int i = 2; i <= n; ++i) {
        catalan[i] = 0;
        for (int j = 0; j < i; ++j)
            catalan[i] += catalan[j] * catalan[i - j - 1];
    }
    return catalan[n];
}

int main() {

    int tc;
    cin >> tc;
    while (tc--) {

        int n;
        cin >> n;

        ul res = getBstCount(n);
        cout << res << '\n';
    }

    return 0;
}
