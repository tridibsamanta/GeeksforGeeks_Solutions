/**
 * Title   : Shortest path from 1 to n
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n/0
 **/

#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin >> t;

	while(t--)
	{
	    int n;
	    cin>>n;

	    int res = 0;
	    while(n != 1)
	    {
	        if (n % 3 == 0)
	            n /= 3;
	        else
	            --n;
	        ++res;
	    }
	    cout << res << '\n';
	}
	return 0;
}
