/**
 * Title   : Triplet Sum in Array
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/triplet-sum-in-array/0
 **/

#include<bits/stdc++.h>
using namespace std;

bool FindTriplet(int arr[], int n, int sum) {

    /* USING TWO POINTER TECHNIQUE */

    sort(arr, arr + n);

    int l, r;

    for(int i = 0; i < n - 2; ++i) {

        l = i + 1;
        r = n - 1;

        while (l < r) {
            if (arr[i] + arr[l] + arr[r] == sum)
                return true;
            else if (arr[i] + arr[l] + arr[r] < sum)
                ++l;
            else
                --r;
        }
    }
    return false;
}

int main()
 {
     int tc;
     cin >> tc;
     while (tc--) {

         int n, x;
         cin >> n >> x;

         int arr[n];
         for(int i = 0; i < n; ++i)
            cin >> arr[i];

         cout << (FindTriplet(arr, n, x) ? "1" : "0") << '\n';
     }
     return 0;
}
