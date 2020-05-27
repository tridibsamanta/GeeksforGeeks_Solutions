/**
 * Title   : Find Missing And Repeating
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/find-missing-and-repeating/0
 **/

#include<bits/stdc++.h>
using namespace std;

void findMissingRepeating(int arr[], int n) {

    int aux[n + 1] = {0}; // Auxiliary freq check array

    for (int i = 0; i < n; ++i) {
        if (aux[arr[i]] != 0)
            cout << arr[i] << ' ';
        else
            ++aux[arr[i]];
    }

    for (int i = 1; i <= n; ++i) {
        if (aux[i] == 0) {
            cout << i << '\n';
            return;
        }
    }
}


int main() {
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        findMissingRepeating(arr, n);
    }
    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/
