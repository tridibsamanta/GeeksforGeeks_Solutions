/**
 * Title   : Two Repeated Elements
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/two-repeated-elements/0
 **/

#include<bits/stdc++.h>
using namespace std;

int main() {

	int tc;
	cin >> tc;
	while (tc--) {

		int N;
		cin >> N;

		int arr[N+2];
		for (int i = 0; i < N+2; ++i)
		    cin >> arr[i];

		for (int i = 0; i < N+2; ++i) {
		    if (arr[abs(arr[i])] >= 0)
		        arr[abs(arr[i])] = -arr[abs(arr[i])];
		    else
		        cout << abs(arr[i]) << " ";
		}
		cout << "\n";
	}

	return 0;
}
