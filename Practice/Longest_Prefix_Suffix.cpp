/**
 * Title   : Longest Prefix Suffix
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1
 **/

// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++
class Solution{
public:


	int lps(string s)
	{

	    int n = s.size();

        vector<int> lps(n, 0);

        int i = 1, j = 0;

        while (i < n) {

            if (s[i] == s[j]) {
                lps[i] = j + 1;
                ++i;
                ++j;
            }
            else {
                if (j != 0) {
                    j = lps[j - 1];
                }
                else {
                    lps[i] = 0;
                    ++i;
                }
            }
        }

        return lps[n - 1];
	}
};

// { Driver Code Starts.

int main()
{


   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends
