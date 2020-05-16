/**
 * Title   : Next larger element
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/next-larger-element/0
 **/

#include<bits/stdc++.h>
using namespace std;

void replaceNearestGreater(long long int arr[], int n) {
    stack<long long int> S;
    long long int res[n];
    for (int i = n - 1; i >= 0; --i) {
        while (!S.empty() && arr[i] >= S.top())
            S.pop();

        if (S.empty())
            res[i] = -1;
        else
            res[i] = S.top();

        S.push(arr[i]);
    }
    for (int i = 0; i < n; ++i)
        cout << res[i] << " ";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        long long int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        replaceNearestGreater(arr, n);
        cout << '\n';
    }
    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/
