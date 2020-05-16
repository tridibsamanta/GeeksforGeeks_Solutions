/**
 * Title   : Greater on right side
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/greater-on-right-side/0
 **/

#include<bits/stdc++.h>
using namespace std;

void replaceRightGreatest(int arr[], int n) {
    int rightMax = arr[n - 1];
    arr[n - 1] = -1;
    for (int i = n - 2; i >= 0; --i) {
        int temp = arr[i];
        arr[i] = rightMax;
        if (temp > rightMax)
            rightMax = temp;
    }
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << '\n';
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
        replaceRightGreatest(arr, n);
    }
    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(1)
*/
