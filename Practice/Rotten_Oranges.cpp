/**
 * Title   : Rotten Oranges
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/rotten-oranges/0
 **/

#include<bits/stdc++.h>
using namespace std;

class Solution {
 public:

    int orangesRotting(vector<vector<int> > &grid) {

        static int rowPos[] = {-1, 1, 0, 0};
        static int colPos[] = {0, 0, -1, 1};

        int r = grid.size();
        int c = grid[0].size();

        int freshCount = 0, time = 0;
        queue<pair<int, int> > q;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 1)
                    ++freshCount;
                else if (grid[i][j] == 2)
                    q.push(make_pair(i, j));
            }
        }

        if (freshCount == 0)
            return 0;

        if (q.empty())
            return -1;

        while (!q.empty()) {

            ++time;
            int element = q.size();

            while (element--) {

                pair<int, int> curr = q.front();
                q.pop();

                for (int i = 0; i < 4; ++i) {

                    int adjX = curr.first + rowPos[i];
                    int adjY = curr.second + colPos[i];

                    if ((adjX >= 0 && adjX < r) && (adjY >= 0 && adjY < c) &&
                        (grid[adjX][adjY] == 1)) {

                        grid[adjX][adjY] = 2;
                        --freshCount;
                        q.push(make_pair(adjX, adjY));
                    }
                }
            }
        }
        return (freshCount > 0) ? -1 : --time;
    }
};

int main() {

    int t;
    cin >> t;
    while (t--) {

        int r, c;
        cin >> r >> c;

        vector<vector<int> > grid(r);

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                int x;
                cin >> x;
                grid[i].emplace_back(x);
            }
        }

        Solution ob;

        int res = ob.orangesRotting(grid);
        cout << res << '\n';
    }

    return 0;
}
