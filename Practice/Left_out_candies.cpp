/**
 * Title   : Left out candies
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/left-out-candies/0
 **/

#include<bits/stdc++.h>
using namespace std;

int findLeftCandies(int n, int m) {

    if (n == 0)
        return m;
    if (m == 0 || n == 1)
        return 0;

    int leftover = m % ((n *(n + 1)) / 2);

    for (int i = 1; i <= n; ++i) {
        if (leftover < i)
            break;
        else
            leftover -= i;
    }

    return leftover;

}

int main() {
    int T;
    cin >> T;
    while (T--) {
    int n, m;
    cin >> n >> m;
    int res = findLeftCandies(n, m);
    cout << res << '\n';
    }
    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(1)
*/
