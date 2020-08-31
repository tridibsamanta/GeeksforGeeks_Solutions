/**
 * Title   : Rotate by 90 degree
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/rotate-by-90-degree/0
 **/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        vector<vector<int> > A(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int x;
                cin >> x;
                A[i].emplace_back(x);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int temp = A[i][j];
                A[i][j] = A[j][i];
                A[j][i] = temp;
            }
        }

        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                int temp = A[i][j];
                A[i][j] = A[n - 1 - i][j];
                A[n - 1 - i][j] = temp;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << A[i][j] << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}
