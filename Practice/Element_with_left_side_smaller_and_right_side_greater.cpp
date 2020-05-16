/**
 * Title   : Element with left side smaller and right side greater
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/unsorted-array/0
 **/

#include<bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n) {

    int leftMax[n], rightMin[n];

    leftMax[0] = INT_MIN;
    for (int i = 1; i < n; ++i)
        leftMax[i] = max(leftMax[i - 1], arr[i - 1]);

    rightMin[n - 1] = INT_MAX;
    for (int i = n - 2; i >= 0; --i)
        rightMin[i] = min(rightMin[i + 1], arr[i + 1]);

    for (int i = 1; i < n - 1; ++i) {
        if (arr[i] >= leftMax[i] && arr[i] <= rightMin[i])
            return arr[i];
    }
    return -1;
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
        cout << findElement(arr, n) << '\n';
    }
    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/
