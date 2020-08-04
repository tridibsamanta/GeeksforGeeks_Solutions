/**
 * Title   : Check an Integer is power of 3 or not
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/check-a-integer-is-power-of-3-or-not/0
 **/

#include<iostream>
using namespace std;

/*
bool isPowerOfThree(int n) {
    return 1162261467 % n == 0;
}
*/

bool isPowerOfThree(int n) {
    if (n < 1)
        return false;

    while (n % 3 == 0)
        n /= 3;

    return n == 1;
}

int main()
 {
	int t;
	cin >> t;
	while (t--) {

	    int n;
	    cin >> n;

	    if (isPowerOfThree(n))
	        cout << "Yes\n";
	    else
	        cout << "No\n";
	}
	return 0;
}
