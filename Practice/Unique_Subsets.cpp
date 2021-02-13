/**
 * Title   : Unique Subsets
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/subsets-1587115621/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


void AllSubsetsUtil(int idx, vector<int>& A, vector<int>& curr, vector<vector<int>>& ans) {

    ans.emplace_back(curr);

    for (int i = idx; i < A.size(); ++i) {

        if (i > idx && A[i] == A[i - 1])
            continue;

        curr.emplace_back(A[i]);

        AllSubsetsUtil(i + 1, A, curr, ans);

        curr.pop_back();
    }
}

vector<vector<int> > AllSubsets(vector<int> A, int n) {

    sort(A.begin(), A.end());

    vector<vector<int>> ans;
    vector<int> curr;

    AllSubsetsUtil(0, A, curr, ans);

    return ans;
}


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }

        vector<vector<int> > result = AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}


  // } Driver Code Ends
