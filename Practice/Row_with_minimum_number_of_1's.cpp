/**
 * Title   : Row with minimum number of 1's
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/row-with-minimum-number-of-1s5430/1
 **/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRow(int N, int M, vector<vector<int>> A) {

        int minRowIdx = 0, minOneCount = INT_MAX;

        for (int i = 0; i < N; ++i) {

            int currOneCount = 0;

            for (int j = 0; j < M; ++j) {
                if (A[i][j] == 1)
                    ++currOneCount;
            }

            if (currOneCount < minOneCount) {
                minOneCount = currOneCount;
                minRowIdx = i;
            }
        }

        return ++minRowIdx;

    }
};
// T.C. - O(N * M)
// S.C. - O(N * M)


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(N, M, A) << "\n";
    }
}  // } Driver Code Ends
