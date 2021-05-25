/**
 * Title   : Steps by Knight
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    bool isPositionValid(int x, int y, int N) {
        return ((x > 0 && x <= N) && (y > 0 && y <= N));
    }

	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N) {

	    static int xPos[] = {1, 2, 2, 1, -1, -2, -2, -1};
        static int yPos[] = {2, 1, -1, -2, -2, -1, 1, 2};

	    int x = TargetPos[0], y = TargetPos[1];
	    int curr_x = KnightPos[0], curr_y = KnightPos[1];

	    // Handle out-of-bounds start / target position of knight
	    if (!isPositionValid(x, y, N) || !isPositionValid(curr_x, curr_y, N)) {
	        return -1;
	    }

	    // Knight is already at the target position
	    if (curr_x == x && curr_y == y) {
	        return 0;
	    }

	    vector<vector<bool> > visited(N+1, vector<bool> (N+1, false));
	    visited[curr_x][curr_y] = true; // Mark start position as visited

	    queue<pair<int, int> > q;
	    q.push(make_pair(curr_x, curr_y)); // Enqueue start position

	    int minMoves = 0;

	    while (!q.empty()) {

	        int sz = q.size(); // Total valid moves from current position

	        for (int i = 0; i < sz; ++i) {

	            auto curr = q.front();
	            q.pop();

	            curr_x = curr.first;
	            curr_y = curr.second;

	            // Knight has reached the target node
	            if (curr_x == x && curr_y == y) {
	                return minMoves;
	            }

	            // Iterate over all possible moves from current position
	            for (int k = 0; k < 8; ++k) {

	                int adj_x = curr_x + xPos[k];
	                int adj_y = curr_y + yPos[k];

	                if (isPositionValid(adj_x, adj_y, N) && !visited[adj_x][adj_y]) {
	                    q.push(make_pair(adj_x, adj_y));
	                    visited[adj_x][adj_y] = true;
	                }
	            }
	        }

	        ++minMoves; // knight moves 1 step
	    }

	    return minMoves;
	}
};

// T.C. - O(N^2)
// S.C. - O(N^2)


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
