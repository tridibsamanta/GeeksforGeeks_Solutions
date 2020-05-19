/**
 * Title   : Set Bits
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/set-bits/0
 **/

#include<bits/stdc++.h>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << countSetBits(n) << '\n';
    }
    return 0;
}
