/**
 * Title   : Power Set
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/power-set4302/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

/* Approach 1 (Recursive) */

class Solution{
	public:
	    void AllPossibleStringsUtil(int idx, string& s, string& curr, vector<string>& ans) {

	        if (curr.length() > 0) {
	            ans.emplace_back(curr);
	        }

	        for (int i = idx; i < s.length(); ++i) {

	            curr.push_back(s[i]);

	            AllPossibleStringsUtil(i + 1, s, curr, ans);

	            curr.pop_back();
	        }
	    }

		vector<string> AllPossibleStrings(string s){

		    vector<string> ans;
		    string curr = "";

		    AllPossibleStringsUtil(0, s, curr, ans);

		    sort(ans.begin(), ans.end());

		    return ans;
		}
};

/* Approach 2 (Iterative) */

/*
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){

		    int n = s.length(), m = pow(2, n);

		    vector<string> res;

		    for (int i = 1; i < m; ++i) {

		        string curr = "";

		        for (int j = 0; j < n; ++j) {

		            if (i & (1 << j))
		                curr += s[j];
		        }

		        res.emplace_back(curr);
		    }

		    sort(res.begin(), res.end());

		    return res;
		}
};
*/


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends
