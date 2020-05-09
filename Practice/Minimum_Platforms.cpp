/**
 * Title   : Minimum Platforms
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/minimum-platforms/0
 **/

#include<bits/stdc++.h>
using namespace std;

int minimumPlatforms(int arrival[], int departure[], int n) {

    sort(arrival, arrival + n);
    sort(departure, departure + n);

    int i = 0, j = 0, pCount = 0, pMax = 0;

    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
            ++pCount;
            ++i;
        }
        else { // (arrival[i] > departure[j])
            --pCount;
            ++j;
        }
        pMax = max(pMax, pCount);
    }
     return pMax;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arrival[n], departure[n];
        for (int i = 0; i < n; ++i)
            cin >> arrival[i];
        for (int i = 0; i < n; ++i)
            cin >> departure[i];
        int res = minimumPlatforms(arrival, departure, n);
        cout << res << '\n';
    }
}
