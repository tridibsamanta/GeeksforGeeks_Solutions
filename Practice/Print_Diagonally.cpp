/**
 * Title   : Print Diagonally
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/print-diagonally/0
 **/

#include<bits/stdc++.h>
using namespace std;

void diagonalPrint(vector<vector<int> > mat) {

    int r = mat.size(), c = mat[0].size();

    for (int k = 0; k < c; ++k) {

        int row = 0, col = k;

        while(col >= 0) {
            cout << mat[row][col] << ' ';
            ++row;
            --col;
        }
    }

    for (int k = 1; k < r; ++k) {

        int row = k, col = c - 1;

        while (row < r) {
            cout << mat[row][col] << ' ';
            ++row;
            --col;
        }
    }
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        vector<vector<int> > mat(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int x;
                cin >> x;
                mat[i].emplace_back(x);
            }
        }

        diagonalPrint(mat);
        cout << '\n';

    }

    return 0;
}
