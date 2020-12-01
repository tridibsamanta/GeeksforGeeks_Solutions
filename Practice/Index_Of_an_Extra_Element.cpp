/**
 * Title   : Index Of an Extra Element
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/index-of-an-extra-element/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int findExtra(int a[], int b[], int n);
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> b[i];
        }
        cout << findExtra(a, b, n) << endl;
    }
}// } Driver Code Ends


/*Complete the function below*/

/*
int findExtra(int a[], int b[], int n) {

    bool found = false;

    int i = 0;

    for (; i < n - 1; ++i) {
        if (a[i] != b[i])
            return i;
    }

    return n - 1;
}
*/

int findExtra(int a[], int b[], int n) {

    int low = 0, high = n - 1, idx = n - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (a[mid] == b[mid])
            low = mid + 1;
        else {
            high = mid - 1;
            idx = mid;
        }
    }

    return idx;
}
