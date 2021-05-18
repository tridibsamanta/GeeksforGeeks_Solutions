/**
 * Title   : XOR of a given range
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/xor-of-a-given-range/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int getXor(vector<int>&nums, int a, int b){
        int res = 0;
        for (int i = a; i <= b; ++i) {
            res ^= nums[i];
        }
        return res;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--){
        int n, a, b;
        cin >> n >> a >> b;
        vector<int>nums(n);
        for(int i = 0; i < n; i++)cin >> nums[i];
        if(a > b)swap(a, b);
        Solution obj;
        int ans = obj.getXor(nums, a, b);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
