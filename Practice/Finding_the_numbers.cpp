/**
 * Title   : Finding the numbers
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/finding-the-numbers/0
 **/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int tc;
    cin >> tc;
    while(tc--) {

    int k;
    cin >> k;

    int n = (2 * k) + 2;

    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int x = arr[0];
    for (int i = 1; i < n; ++i)
        x ^= arr[i];

    int r_set = x & ~(x - 1), num1 = 0, num2 = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i] & r_set)
            num1 ^= arr[i];
        else
            num2 ^= arr[i];
    }

    if (num1 < num2)
        cout << num1 << ' ' << num2 << '\n';
    else
        cout << num2 << ' ' << num1 << '\n';
    }

    return 0;
}
