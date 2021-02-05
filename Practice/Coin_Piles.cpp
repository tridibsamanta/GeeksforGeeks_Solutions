/**
 * Title   : Coin Piles
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/coin-piles/0
 **/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMinRemovals(vector<int>& coins, int n, int k) {

        sort(coins.begin(), coins.end());

        int res = INT_MAX, preSum = 0;

        for (int i = 0; i < n; ++i) {

            int curr = preSum;
            preSum += coins[i];

            for (int j = n - 1; j > i; --j) {

                if (coins[j] - coins[i] - k > 0)
                    curr += coins[j] - coins[i] - k;
                else
                    break;
            }

            res = min(res, curr);
        }

        return res;
    }
};

int main() {

    Solution ob;

    int t;
    cin >> t;
    while (t--) {

    	int n, k;
    	cin >> n >> k;

    	vector<int> coins(n);

    	for (int i = 0; i < n; ++i) {
    	    cin >> coins[i];
    	}

        int res = ob.getMinRemovals(coins, n, k);
        cout << res << '\n';
    }

    return 0;
}
