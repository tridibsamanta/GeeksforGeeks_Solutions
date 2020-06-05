/**
 * Title   : Nth catalan number
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/nth-catalan-number/0
 **/

#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;
using namespace std;

cpp_int getCatalanNumber(int n) {

    cpp_int catalan[n + 1];

    catalan[0] = 1; catalan[1] = 1;

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

        cpp_int res = getCatalanNumber(n);
        cout << res << '\n';
    }

    return 0;
}
