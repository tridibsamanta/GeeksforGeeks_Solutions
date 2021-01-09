/**
 * Title   : Count Occurences of Anagrams
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {

	    int n = txt.length(), k = pat.length();

	    unordered_map<char, int> ump;

	    for (int i = 0; i < k; ++i) {
	        ++ump[pat[i]];
	    }

	    int cnt = ump.size(), ans = 0;
	    int i = 0, j = 0;

	    while (j < n) {

	        if (ump.find(txt[j]) != ump.end()) {

	            if (--ump[txt[j]] == 0)
	                --cnt;
	        }

	        if (j - i + 1 < k) {
	            ++j;
	        }
	        else if (j - i + 1 == k) {

	            if (cnt == 0)
	                ++ans;

	            if (ump.find(txt[i]) != ump.end()) {

                    if (++ump[txt[i]] == 1)
                        ++cnt;
	            }

	            ++i;
	            ++j;
	        }
	    }

	    return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
