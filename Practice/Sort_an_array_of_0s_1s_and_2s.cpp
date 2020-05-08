/**
 * Title   : Sort an array of 0s, 1s and 2s
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0
 **/

#include<iostream>
using namespace std;

void dutchNationalFlagProblem(int arr[], int n) {

    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {

        switch (arr[mid]) {
        //If the element is 0
        case 0: {
            swap(arr[mid], arr[low]);
            ++mid; ++low;
            break;
        }
        //If the element is 1
        case 1: {
            ++mid;
            break;
        }
        //If the element is 2
        case 2: {
            swap(arr[mid], arr[high]);
            --high;
            break;
        }
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

        dutchNationalFlagProblem(arr, n);

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

