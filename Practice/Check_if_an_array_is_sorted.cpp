/**
 * Title   : Check if an array is sorted
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/check-if-an-array-is-sorted/0
 **/

#include<bits/stdc++.h>
using namespace std;

int isArraySorted(int arr[], int n) {
    if (n == 1)
        return 1;
    if (arr[n-1] < arr[n-2])
        return 0;
    else
        return isArraySorted(arr, n-1);
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
    int N;
    cin >> N;
    int C[N];
    for(int i = 0; i < N; ++i)
        cin >> C[i];
    cout << (isArraySorted(C, N) ? "1" : "0") << "\n";
    }
    return 0;
}
