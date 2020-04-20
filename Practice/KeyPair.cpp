/**
 * Title   : Key Pair
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/key-pair/0
 **/

#include<bits/stdc++.h>
using namespace std;

bool FindTriplet(int arr[], int n, int sum) {

    sort(arr, arr + n);

    int l = 0, r = n-1;

    while (l < r) {
        if (arr[l] + arr[r] == sum)
            return true;
        else if (arr[l] + arr[r] < sum)
            ++l;
        else
            --r;
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

         cout << (FindTriplet(arr, n, x) ? "Yes" : "No") << '\n';
     }
     return 0;
}
