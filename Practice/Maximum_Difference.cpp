/**
 * Title   : Maximum Difference
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/maximum-difference/0
 **/

#include<bits/stdc++.h>
using namespace std;

int findMaxDiff(int arr[], int n) {
    int minElement = arr[0], maxDiff = INT_MIN;
    for (int i = 1; i < n; ++i) {
        if (arr[i] - minElement > maxDiff)
            maxDiff = arr[i] - minElement;
        if (arr[i] < minElement)
            minElement = arr[i];
    }
    return maxDiff;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        int res = findMaxDiff(arr, n);
        cout << res << '\n';
    }
    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(1)
*/
