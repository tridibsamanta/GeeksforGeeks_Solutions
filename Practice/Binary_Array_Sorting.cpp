/**
 * Title   : Binary Array Sorting
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/binary-array-sorting/0
 **/

#include<iostream>
using namespace std;

void binaryArraySorting(int arr[], int n) {

    int low = 0, high = n - 1;

    while (low <= high) {
        if (arr[low] == 0)
            ++low;
        else {
            swap(arr[low],arr[high--]);
        }
    }

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

        binaryArraySorting(arr, n);

        for(int i = 0; i < n; ++i)
            cout << arr[i] << " ";

        cout << "\n";
    }
    return 0;
}

/*
 ~ T.C. - O(n)
 ~ S.C. - O(1)
*/

