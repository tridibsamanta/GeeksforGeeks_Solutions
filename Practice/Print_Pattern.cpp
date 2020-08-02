/**
 * Title   : Print Pattern
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/print-pattern/0/
 **/

#include<iostream>
using namespace std;

void printPattern(int n) {

    if (n == 0 || n < 0) {
        cout << n << ' ';
        return;
    }

    cout << n << ' ';

    printPattern(n - 5);

    cout << n << ' ';

}

int main()
 {
	int t;
	cin >> t;
	while (t--) {

	    int n;
	    cin >> n;

	    printPattern(n);
	    cout << '\n';

	}
	return 0;
}
