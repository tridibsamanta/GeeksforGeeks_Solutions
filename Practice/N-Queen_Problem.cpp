/**
 * Title   : N-Queen Problem
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1
 **/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool col[11], diag1[21], diag2[21];
    vector<vector<int> > res;

    void nQueenUtil(int y, int n, vector<int>& temp){

        if (y == n) {
            res.emplace_back(temp);
            return;
        }

        for (int i = 0; i < n; ++i) {

            if (col[i] || diag1[i + y] || diag2[i - y + n - 1])
                continue;

            col[i] = diag1[i + y] = diag2[i - y + n - 1] = true;

            temp.emplace_back(i+1);

            nQueenUtil(y + 1, n, temp);

            col[i] = diag1[i + y] = diag2[i - y + n - 1] = false;
            temp.pop_back();
        }
    }

    vector<vector<int>> nQueen(int n) {

        memset(col, false, sizeof(col));
        memset(diag1, false, sizeof(diag1));
        memset(diag2, false, sizeof(diag2));
        vector<int> temp;

        nQueenUtil(0, n, temp);

        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
