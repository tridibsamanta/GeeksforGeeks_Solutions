/**
 * Title   : Largest prime factor
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/largest-prime-factor/0
 **/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll getLargestPrimeFactor(ll n) {

    while (n % 2 == 0) {
        n /= 2;
    }

    ll ans = 2;

    if (n == 1)
        return ans;

    for (int i = 3; i <= sqrt(n); i += 2) {

        while (n % i == 0) {
            ans = i;
            n /= i;
        }
    }

    if (n > 2)
        return n;
    else
        return ans;
}

int main()
 {
	ll tc;
	cin >> tc;
	while (tc--) {

	   ll n;
	   cin >> n;

	   ll res = getLargestPrimeFactor(n);
	   cout << res << '\n';

	}
	return 0;
}
