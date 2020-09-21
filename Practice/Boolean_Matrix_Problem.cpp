/**
 * Title   : Boolean Matrix Problem
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/boolean-matrix-problem/0
 **/

#include<bits/stdc++.h>
using namespace std;

// Approach 1: T.C. - O(r * c), S.C. - O(r + c)
/*
void setOnes(vector<vector<int> > &matrix) {

    int r = matrix.size();
    int c = matrix[0].size();

    bool row[r], col[c];

    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (matrix[i][j] == 1) {
                row[i] = col[j] = true;
            }
        }
    }

    for (int i = 0; i < r; ++i) {
        if (row[i]) {
            for (int j = 0; j < c; ++j)
                matrix[i][j] = 1;
        }
    }

    for (int i = 0; i < c; ++i) {
        if (col[i]) {
            for (int j = 0; j < r; ++j)
                matrix[j][i] = 1;
        }
    }
}
*/

// Approach 2: T.C. - O(r * c), S.C. - O(1)

void setOnes(vector<vector<int> > &matrix) {

    int r = matrix.size();
    int c = matrix[0].size();

    bool isColOne = false;

    for (int i = 0; i < r; ++i) {

        if (matrix[i][0] == 1)
            isColOne = true;

        for (int j = 1; j < c; ++j) {

            if (matrix[i][j] == 1)
                matrix[i][0] = matrix[0][j] = 1;

        }

    }

    for (int i = 1; i < r; ++i) {

        for (int j = 1; j < c; ++j) {

            if (matrix[i][0] == 1 || matrix[0][j] == 1)
                matrix[i][j] = 1;

        }
    }

    if (matrix[0][0] == 1) {
        for (int i = 1; i < c; ++i)
            matrix[0][i] = 1;
    }

    if (isColOne) {
        for (int i = 0; i < r; ++i)
            matrix[i][0] = 1;
    }

}

int main() {

    int t;
    cin >> t;
    while(t--) {

        int r, c;
        cin >> r >> c;

        vector<vector<int> > matrix(r);

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                int x;
                cin >> x;
                matrix[i].emplace_back(x);
            }
        }

        setOnes(matrix);

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << matrix[i][j] << ' ';
            }
            cout << '\n';
        }

    }

    return 0;
}
