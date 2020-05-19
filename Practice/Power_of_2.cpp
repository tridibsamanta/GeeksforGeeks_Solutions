/**
 * Title   : Power of 2
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/power-of-2/0
 **/

#include<bits/stdc++.h>
using namespace std;

bool checkPowerOfTwo(long long int n) {
    if (n < 1)
        return false;
    return !(n & (n - 1));
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long int n;
        cin >> n;
        cout << (checkPowerOfTwo(n) ? "YES" : "NO") << '\n';
    }
    return 0;
}
