/**
 * Title   : Adding Ones
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/adding-ones/0
 **/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		int n, k;
		cin >> n >> k;

		int arr[n+1] = {0};

		int k_val;
		for (int i = 0; i < k; ++i) {
		    cin >> k_val;
		    for(int j = k_val; j <= n; ++j) {
		        ++arr[j];
		    }
		}

		for(int i = 1; i <= n; ++i)
		    cout << arr[i] << " ";

		cout << "\n";

	}

	return 0;
}
