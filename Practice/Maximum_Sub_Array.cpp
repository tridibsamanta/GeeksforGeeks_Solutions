/**
 * Title   : Maximum Sub Array
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/maximum-sub-array/0
 **/

#include<bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	while(tc--) {

	    int n;
	    cin >> n;

	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];

	    int j = 0, x = 0, start = 0, end = 0, curr_sum = 0, max_sum = 0;

	    while (j<n) {
	        while (j < n && arr[j] < 0)
	           ++j;
	        x = j;
	        curr_sum = 0;
	        while (j < n && arr[j] >= 0) {
	            curr_sum += arr[j];
	            ++j;
	        }
	        if (j > x && curr_sum >= max_sum) {
	             start = x; end = j;
	             max_sum = curr_sum;
	        }
	     }

	     for(int i = start; i < end; ++i)
	         cout << arr[i] << " ";
	     cout << "\n";
	}
	return 0;
}
