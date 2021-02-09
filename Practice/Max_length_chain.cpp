/**
 * Title   : Max length chain
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/max-length-chain/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}

		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/


static bool comparator(const vector<int>& a, const vector<int>& b) {
    if (a[1] == b[1])
        return a[0] >= b[0];
    return a[1] < b[1];
}

int maxChainLen(struct val p[],int n) {

    vector<vector<int> > nums(n);

    for (int i = 0; i < n; ++i) {
        nums[i].emplace_back(p[i].first);
        nums[i].emplace_back(p[i].second);
    }

    sort(nums.begin(), nums.end(), comparator);

    vector<int> dp(n, 1);

    int maxCnt = 1;

    for (int i = 1; i < n; ++i) {

        for (int j = 0; j < i; ++j) {

            if (nums[i][0] > nums[j][1])
                dp[i] = max(dp[i], dp[j] + 1);
        }

        maxCnt = max(maxCnt, dp[i]);
    }

    return maxCnt;
}
