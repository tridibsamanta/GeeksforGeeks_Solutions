/**
 * Title   : Finding Number
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/finding-number/0
 **/

#include<iostream>
using namespace std;

int findMaxBitonicIndex(int arr[], int low, int high) {

    // If array has 1 element
    if (low == high)
        return low;

    // If array has 2 elements
    if (high == low + 1 && arr[low] > arr[high])
        return low;

    if (high == low + 1 && arr[high] > arr[low])
        return high;

    // If array has more than 2 elements
    int mid = (low + high) / 2;

    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        return mid;
    if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1])
        return findMaxBitonicIndex(arr, low, mid - 1);
    else
        return findMaxBitonicIndex(arr, mid + 1, high);
}

int ascendingBinarySearch(int arr[], int low, int high, int key) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        else if (arr[mid] > key)
            return ascendingBinarySearch(arr, low, mid - 1, key);

        else
            return ascendingBinarySearch(arr, mid + 1, high, key);
    }

    return -1;
}

int descendingBinarySearch(int arr[], int low, int high, int key) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        else if (arr[mid] < key)
            return descendingBinarySearch(arr, low, mid - 1, key);

        else
            return descendingBinarySearch(arr, mid + 1, high, key);
    }

    return -1;
}

int main() {

    int tc;
    cin >> tc;
    while (tc--) {

        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        int x;
        cin >> x;

        int max_index = findMaxBitonicIndex(arr, 0, n-1);

        if (x > arr[max_index])
            cout << "-1\n";
        else if (arr[max_index] == x)
            cout << max_index << "\n";
        else {
            int pos;

            //Searching for the element in the subarray left to the maximum element
            pos = ascendingBinarySearch(arr, 0, max_index - 1, x);
            if (pos != -1)
                cout << pos << "\n";
            else {
                //Searching for the element in the subarray right to the maximum element
                pos = descendingBinarySearch(arr, max_index + 1, n-1, x);
                if (pos != -1)
                    cout << pos << "\n";
                else
                    cout << "-1\n";
            }
        }

    }
}
