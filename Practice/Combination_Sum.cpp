/**
 * Title   : Combination Sum
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

/* Approach 1 */

void combinationSumUtil(int idx, int target, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {

    if (target == 0) {
        ans.emplace_back(curr);
        return;
    }

    for (int i = idx; i < nums.size(); ++i) {

        if (nums[i] > target)
            break;

        curr.emplace_back(nums[i]);

        combinationSumUtil(i, target - nums[i], nums, curr, ans);

        curr.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {

    set<int> s;

    for (auto i : A)
        s.insert(i);

    vector<int> nums;

    for (auto i : s)
        nums.emplace_back(i);

    vector<vector<int>> ans;
    vector<int> curr;

    combinationSumUtil(0, B, nums, curr, ans);

    return ans;
}


/* Approach 2 */

/*
void combinationSumUtil(int idx, int target, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {

    if (target == 0) {
        ans.emplace_back(curr);
        return;
    }

    if (idx == nums.size() || nums[idx] >  target)
        return;

    if (nums[idx] <= target) {

        curr.emplace_back(nums[idx]);

        combinationSumUtil(idx, target - nums[idx], nums, curr, ans);

        curr.pop_back();
    }

    combinationSumUtil(idx + 1, target, nums, curr, ans);
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {

    set<int> s;

    for (auto i : A)
        s.insert(i);

    vector<int> nums;

    for (auto i : s)
        nums.emplace_back(i);

    vector<vector<int>> ans;
    vector<int> curr;

    combinationSumUtil(0, B, nums, curr, ans);

    return ans;
}
*/


// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }
        int sum;
        cin>>sum;
        vector<vector<int> > result;
   		result=combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
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
}	  // } Driver Code Ends
