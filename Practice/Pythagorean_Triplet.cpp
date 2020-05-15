/**
 * Title   : Pythagorean Triplet
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/pythagorean-triplet/0
 **/

#include<bits/stdc++.h>
using namespace std;

bool findPythagoreanTriplet(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        arr[i] *= arr[i];
    sort(arr, arr + n);
    for (int i = n - 1; i > 1; --i) {
        int leftPtr = 0, rightPtr = i - 1;
        while (leftPtr < rightPtr) {
            if (arr[leftPtr] + arr[rightPtr] == arr[i])
                return true;
            else {
                if (arr[leftPtr] + arr[rightPtr] < arr[i])
                    ++leftPtr;
                else
                    --rightPtr;
            }
        }
    }
    return false;
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
        cout << (findPythagoreanTriplet(arr, n) ? "Yes" : "No") << '\n';
    }
    return 0;
}

/*
 ~ Time Complexity   : O(n^2)
 ~ Space Complexity  : O(1)
*/
