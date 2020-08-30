/**
 * Title   : Triangular Number
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/triangular-number/0/
 **/

#include<bits/stdc++.h>
using namespace std;

bool isTriangularNumber(int num) {

    int n = sqrt(2 * num);

	if(n * (n + 1) == (2 * num))
	    return true;

	return false;
}

int main() {

	int t;
	cin >> t;
	while (t--) {

	    int n;
	    cin >> n;

	    if (isTriangularNumber(n))
	        cout << 1 << '\n';
	    else
	        cout << 0 << '\n';

	}

	return 0;
}
