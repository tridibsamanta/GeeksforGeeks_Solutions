/**
 * Title   : Max rectangle
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/max-rectangle/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    vector<int> NS_right_idx, NS_left_idx;

    void nearestSmallerRight(vector<int> heights) {

        int n = heights.size();
        stack<pair<int, int> > nsr;

        for (int i = n - 1; i >= 0; --i) {

            while (!nsr.empty() && heights[i] <= nsr.top().first)
                nsr.pop();

            if (!nsr.empty())
                NS_right_idx[i] = nsr.top().second;
            else
                NS_right_idx[i] = n;

            nsr.emplace(heights[i], i);
        }
    }

    void nearestSmallerLeft(vector<int> heights) {

        int n = heights.size();
        stack<pair<int, int> > nsl;

        for (int i = 0; i < n; ++i) {

            while (!nsl.empty() && heights[i] <= nsl.top().first)
                nsl.pop();

            if (!nsl.empty())
                NS_left_idx[i] = nsl.top().second;
            else
                NS_left_idx[i] = -1;

            nsl.emplace(heights[i], i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        if (n == 1)
            return heights[0];

        NS_right_idx.clear();
        NS_right_idx.resize(n);
        NS_left_idx.clear();
        NS_left_idx.resize(n);

        nearestSmallerRight(heights);
        nearestSmallerLeft(heights);

        int maxArea = INT_MIN;

        for (int i = 0; i < n; ++i) {
            int currArea = heights[i] * (NS_right_idx[i] - NS_left_idx[i] - 1);
            maxArea = max(maxArea, currArea);
        }

        return maxArea;
    }

    int maxArea(int M[MAX][MAX], int n, int m) {

        int maxArea = INT_MIN;
        vector<int> arr(m);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {

                if (M[i][j] == 0)
                    arr[j] = 0;
                else
                    arr[j] += 1;
            }

            maxArea = max(maxArea, largestRectangleArea(arr));
        }

        return maxArea;
    }
};
// T.C. - O(n*m)
// S.C. - O(m)


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends
