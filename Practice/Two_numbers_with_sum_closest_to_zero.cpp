/**
 * Title   : Two numbers with sum closest to zero
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/two-numbers-with-sum-closest-to-zero/0
 **/

#include<bits/stdc++.h>
using namespace std;

void findElements(int arr[], int n) {

    sort(arr, arr + n);

    int l = 0, r = n - 1, sum = 0, minSum = INT_MAX;

    while (l < r) {

        sum = arr[l] + arr[r];

        if (abs(sum) < abs(minSum))
            minSum = sum;

        sum < 0 ? ++l : --r;
    }

    cout << minSum << '\n';
}

int main() {

    int tc;
    cin >> tc;
    while (tc--) {

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findElements(arr, n);

    }

    return 0;
}

/*
 ~ Time Complexity   : O(nlogn)
 ~ Space Complexity  : O(1)
*/
