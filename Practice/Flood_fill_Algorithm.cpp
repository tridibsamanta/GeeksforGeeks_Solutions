/**
 * Title   : Flood fill Algorithm
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/flood-fill-algorithm/0
 **/

#include<bits/stdc++.h>
using namespace std;

int mat[101][101];

void floodFillUtil(int n, int m, int x, int y, int k, int validColor) {

    static int rPos[] = {-1, 1, 0, 0};
    static int cPos[] = {0, 0, -1, 1};

    mat[x][y] = k;

    for (int i = 0; i < 4; ++i) {
        int adjX = x + rPos[i];
        int adjY = y + cPos[i];
        if ((adjX >= 0 && adjX < n) && (adjY >= 0 && adjY < m) && mat[adjX][adjY] == validColor)
            floodFillUtil(n, m, adjX, adjY, k, validColor);
    }
}

void floodFill(int n, int m, int x, int y, int k) {

    int validColor = mat[x][y];
    if (validColor != k) {
        floodFillUtil(n, m, x, y, k, validColor);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << mat[i][j] << ' ';
        }
    }
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> mat[i][j];
            }
        }

        int x, y, k;
        cin >> x >> y >> k;

        floodFill(n, m, x, y, k);
        cout << '\n';
    }

    return 0;
}
