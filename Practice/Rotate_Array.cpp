/**
 * Title   : Rotate Array
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements/0
 **/

#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int> &nums, int s, int e) {
    while (s < e) {
        int temp = nums[s];
        nums[s] = nums[e];
        nums[e] = temp;
        ++s;
        --e;
    }
}

void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, (nums.size() - k) - 1);
    reverse(nums, nums.size() - k, nums.size() - 1);
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> nums;
        int num;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            nums.emplace_back(num);
        }

        rotate(nums, k);

        for (int i = 0; i < n; ++i)
            cout << nums[i] << ' ';

        cout << '\n';
    }

    return 0;
}
