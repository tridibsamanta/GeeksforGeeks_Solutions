/**
 * Title   : First negative integer in every window of size k
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k/0
 **/

#include<bits/stdc++.h>
using namespace std;

void firstNegative(int arr[], int n, int k) {

    list<int> neg;

    int i = 0, j = 0;

    while (j < n) {

        if (arr[j] < 0)
            neg.emplace_back(arr[j]);

        if (j - i + 1 < k) {
            ++j;
        }
        else if (j - i + 1 == k) {

            if (neg.empty()) {
                cout << 0 << ' ';
            }
            else {
                cout << neg.front() << ' ';

                if (arr[i] == neg.front())
                    neg.pop_front();
            }

            ++i;
            ++j;
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

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        int k;
        cin >> k;

        firstNegative(arr, n, k);
        cout << '\n';

    }

    return 0;
}
