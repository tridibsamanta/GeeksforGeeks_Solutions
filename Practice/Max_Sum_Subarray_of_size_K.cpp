/**
 * Title   : Max Sum Subarray of size K
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k/0
 **/

#include<bits/stdc++.h>
using namespace std;

int MaxSubarraySum(int arr[], int n, int k) {

    int windowSum = 0;

    for (int i = 0; i < k; ++i)
        windowSum += arr[i];

    int maxSum = windowSum;

    for (int j = k; j < n; ++j) {
        windowSum += arr[j] - arr[j-k];
        maxSum = max(windowSum, maxSum);
    }

    return maxSum;

}

int main() {

    int tc;
    cin >> tc;
    while(tc --) {

        int n, k;
        cin >> n >> k;

        int arr[n];

        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        int maxSum = MaxSubarraySum(arr, n, k);
        cout << maxSum << "\n";
    }

    return 0;
}

/*
 * Time Complexity  : O(n)
 * Auxiliary Space  : O(1)
*/
