/**
 * Title   : Pascal Triangle
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/pascal-triangle/0
 **/

#include<bits/stdc++.h>
using namespace std;

void printPascalRow(int k) {
    int c = 1;
    for (int i = 1; i <= k; ++i) {
        cout << c << ' ';
        c = c * (k - i) / i;
    }
}

int main() {

	int t;
	cin >> t;
	while (t--) {

	    int k;
	    cin >> k;

	    printPascalRow(k);
	    cout << '\n';
	}

	return 0;
}
