/**
 * Title   : Game of Death in a circle
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/game-of-death-in-a-circle/0
 **/

#include<iostream>
using namespace std;

int josephus(int n, int k) {
    if (n == 1)
        return 1;
    else
        return (josephus(n - 1, k) + k-1) % n + 1;
}


int main()
 {
	int T;
	cin >> T;
	while (T--) {

	    int n, k;
	    cin >> n >> k;

	    int pos = josephus(n, k);
	    cout << pos << "\n";
	}
	return 0;
}
