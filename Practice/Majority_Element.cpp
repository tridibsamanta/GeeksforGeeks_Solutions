/**
 * Title   : Majority Element
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/majority-element/0
 **/

#include<bits/stdc++.h>
using namespace std;

int findMajorityElement(int arr[], int n) {

    int element = 0, count = 0;

    for (int i = 0; i < n; ++i) {
        if (count == 0 || element == arr[i]) {
            element = arr[i];
            ++count;
        }
        else
            --count;
    }

    count = 0;
    for (int i = 0; i < n; ++i) {
        if (element == arr[i])
            ++count;
        if (count > (n / 2))
            return element;
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

    int majority = findMajorityElement(arr, n);
    cout << majority << '\n';

    }
    return 0;
}
