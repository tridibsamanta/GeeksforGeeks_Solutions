/**
 * Title   : Smallest Positive missing number
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number/0
 **/

#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int seperatePositive(int arr[], int n) {

    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] <= 0) {
            swap(&arr[i], &arr[j]);
            ++j;
        }
    }
    return j;
}

int helper(int arr[], int n) {

    for (int i = 0; i < n; ++i)
        if (abs(arr[i]) - 1 < n && arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];

    for (int i = 0; i < n; ++i)
        if (arr[i] > 0)
            return i + 1;

    return n + 1;
}

int findSmallestPositive(int arr[], int n) {
    int pos = seperatePositive(arr, n);
    int ans = helper(arr + pos, n - pos);
    return ans;
}

int main() {

    int t;
    cin >> t;
    while(t--) {

        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        int res = findSmallestPositive(arr, n);
        cout << res << '\n';
    }

    return 0;
}
