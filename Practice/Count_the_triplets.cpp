/**
 * Title   : Count the triplets
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/count-the-triplets/0
 **/

#include<bits/stdc++.h>
using namespace std;

int CountTriplet(int arr[], int n) {

    sort(arr, arr + n);

    int l, r, count = 0;

    for(int i = n-1; i > 1; --i) {
        l = 0;
        r = i - 1;
        while (l < r) {
            if(arr[l] + arr[r] == arr[i]) {
                ++count;
                ++l;
                --r;
            }
            else if (arr[l] + arr[r] < arr[i])
                ++l;
            else
                --r;
        }
    }
    return count;
}

int main()
 {
     int tc;
     cin >> tc;
     while (tc--) {

         int n;
         cin >> n;

         int arr[n];
         for(int i = 0; i < n; ++i)
            cin >> arr[i];

         int c = CountTriplet(arr, n);
         if (c > 0)
            cout << c << "\n";
         else
            cout << "-1\n";

     }
     return 0;
}
