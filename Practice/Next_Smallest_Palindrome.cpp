/**
 * Title   : Next Smallest Palindrome
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/next-smallest-palindrome4740/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
#define ll long long

class Solution{
public:
    vector<int> convertStringToVector(string s) {
        vector<int> res;

    	for (int i = 0; i < s.size(); ++i)
	        res.emplace_back(s[i] - '0');

	    return res;
    }

    string roundUp(string s, ll n) {
	    ll i = n / 2;

	    while (i >= 0) {
		    if (s[i] != '9')
			    break;
		    --i;
	    }

	    if (i < 0) {
		    s = "1" + string (n, '0');
	    }
	    else {
		    ++s[i];

		    for (ll j = i + 1; j < n; ++j)
			    s[j] = '0';
	    }

	    ll j = s.size() - 1; i = 0;

	    while (i < j) {
		    s[j--] = s[i++];
	    }

	    return s;
    }

    vector<int> generateNextPalindromeUtil(int num[], ll m) {

	    string s = "";

	    for (int i = 0; i < m; ++i)
	        s += ('0' + num[i]);

	    string t = s;
	    ll i = 0, j = m - 1;

	    while (i < j) {
    		t[j--] = t[i++];
	    }

	    if (t > s)
		    return convertStringToVector(t);

	    if (m & 1) {
		    if (t[m / 2] == '9')
			    t = roundUp(t, m);
		    else
			    ++t[m / 2];
	    }
	    else {
		    if (t[m / 2] == '9')
			    t = roundUp(t, m);
		    else {
			    ++t[m / 2];
			    ++t[m / 2 - 1];
		    }
	    }

        return convertStringToVector(t);
    }

	vector<int> generateNextPalindrome(int num[], int n) {
	    return generateNextPalindromeUtil(num, n);
	}
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
