/**
 * Title   : Search in a Rotated Array
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number/0
 **/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            while ((nums[i] >= 1 && nums[i] <= n) && (nums[i] != nums[nums[i] - 1]))
                swap(nums[i], nums[nums[i] - 1]);
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        vector<int> nums;

        for (int i = 0; i < n; ++i) {
            int element;
            cin >> element;
            nums.emplace_back(element);
        }

        Solution ob;

        int res = ob.firstMissingPositive(nums);
        cout << res << '\n';
    }

    return 0;
}
