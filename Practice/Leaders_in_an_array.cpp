/**
 * Title   : Leaders in an array
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0
 **/

#include<bits/stdc++.h>
using namespace std;

void findLeaders(int arr[], int n) {
    int max = INT_MIN;
    for (int i = n - 1; i >= 0; --i) {
        if (arr[i] >= max)
            max = arr[i];
        else
            arr[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        if (arr[i] != -1)
            cout << arr[i] << " ";
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        findLeaders(arr, n);
    }
}
