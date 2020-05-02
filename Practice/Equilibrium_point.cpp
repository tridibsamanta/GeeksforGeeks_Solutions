/**
 * Title   : Equilibrium point
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/equilibrium-point/0
 **/

#include<iostream>
using namespace std;

int findEquilibriumIndex(int arr[], int n) {

    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += arr[i];

    int leftSum = 0;
    for (int i = 0; i < n; ++i) {
        sum -= arr[i];
        if (leftSum == sum)
            return i+1;
        leftSum += arr[i];
    }
    return -1;
}

int main()
 {
	int tc;
	cin >> tc;
	while(tc--) {
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i = 0; i < n; ++i)
	        cin >> arr[i];
	    int eq_index = findEquilibriumIndex(arr, n);
	    cout << eq_index << '\n';
	}
	return 0;
}
