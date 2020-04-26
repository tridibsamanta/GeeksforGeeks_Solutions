/**
 * Title   : Searching an element in a sorted array
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/who-will-win/0
 **/

#include<iostream>
using namespace std;

int searchElement(int arr[], int low, int high, int key) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            return searchElement(arr, low, mid - 1, key);
        else
            return searchElement(arr, mid + 1, high, key);
    }
    return -1;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        int index = searchElement(arr, 0, n-1, k);
        cout << (index >= 0 ? "1" : "-1") << "\n";
    }
    return 0;
}
