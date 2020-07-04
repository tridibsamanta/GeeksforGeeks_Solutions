/**
 * Title   : Find the number of islands
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends


/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/

bool isPosValid(vector<int> A[], int rowIdx, int colIdx, vector<bool> visited[], int N, int M) {

    return (rowIdx >= 0) && (rowIdx < N) &&
            (colIdx >= 0) && (colIdx < M) &&
            (A[rowIdx][colIdx]) && (!visited[rowIdx][colIdx]);
}

void dfs(vector<int> A[], int rowIdx, int colIdx, vector<bool> visited[], int N, int M) {

    static int rowNum[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int colNum[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    visited[rowIdx][colIdx] = true;

    for (int k = 0; k < 8; ++k) {
        if (isPosValid(A, rowIdx + rowNum[k], colIdx + colNum[k], visited, N, M))
            dfs(A, rowIdx + rowNum[k], colIdx + colNum[k], visited, N, M);
    }

}

int findIslands(vector<int> A[], int N, int M) {

    vector <bool> visited[N];
    for (int i = 0; i < N; ++i) {
        visited[i] = vector <bool> (M);
        for (int j = 0; j < M; ++j)
            visited[i][j] = false;
    }

    int islandCount = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (A[i][j] && !visited[i][j]) {
                dfs(A, i, j, visited, N, M);
                ++islandCount;
            }
        }
    }

    return islandCount;
}
