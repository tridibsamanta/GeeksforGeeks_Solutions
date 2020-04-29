/**
 * Title   : Rearrange Array Alternately
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately/0/
 **/

#include<bits/stdc++.h>
using namespace std;

void rearrangeArrayAlternately(long long int arr[], long long int n) {

    long long int min_index = 0, max_index = n - 1, max_element = arr[n - 1] + 1;

    for (long long int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            arr[i] += (arr[max_index] % max_element) * max_element;
            --max_index;
        }
        else {
            arr[i] += (arr[min_index] % max_element) * max_element;
            ++min_index;
        }
    }

    for (long long int i = 0; i < n; ++i)
        arr[i] = arr[i] / max_element;

}

int main() {

    int T;
    cin >> T;
    while (T--) {

        long long int n;
        cin >> n;

        long long int arr[n];
        for (long long int i = 0; i < n; ++i)
            cin >> arr[i];

        //sort(arr, arr + n);

        rearrangeArrayAlternately(arr, n);

        for (long long int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << "\n";

    }

    return 0;
}
