/**
 * Title   : Transpose of Matrix
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/transpose-of-matrix/0
 **/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        int mat[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> mat[i][j];

        int matT[n][n];
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                matT[k][i] = mat[i][k];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout << matT[i][j] << ' ';

        cout << '\n';
    }
    return 0;
}
