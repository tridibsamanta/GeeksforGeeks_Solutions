/**
 * Title   : Subarrays with given sum
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/subarray-range-with-given-sum/0
 **/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;
	while (tc--) {

		int n;
		cin>>n;
		vector<int> nums(n, 0);
		vector<int> preSum(n + 1, 0);

		for (int i = 0; i < n; i++) {
			cin >> nums[i];
			preSum[i + 1] = preSum[i] + nums[i];
		}

		int k;
		cin >> k;

		unordered_map<int, int> hm;

		hm[0 + k]++;

		int count = 0;
		for (int i = 1; i < preSum.size(); i++) {
			if (hm.find(preSum[i]) != hm.end())
				count += hm[preSum[i]];
			hm[preSum[i] + k]++;
		}
		cout << count << "\n";
	}
	return 0;
}
