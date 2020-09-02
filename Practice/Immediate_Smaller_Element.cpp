/**
 * Title   : Immediate Smaller Element
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/immediate-smaller-element/0
 **/

#include<bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin >> t;
	while (t--) {

	    int n;
	    cin >> n;

	    int arr[n];
	    for (int i = 0; i < n; ++i)
	        cin >> arr[i];

	    for (int i = 0; i < n - 1; ++i) {
	        if (arr[i + 1] < arr[i])
	            cout << arr[i + 1] << ' ';
	        else
	            cout << -1 << ' ';
	    }

	    cout << -1 << '\n';

	}

	return 0;
}
