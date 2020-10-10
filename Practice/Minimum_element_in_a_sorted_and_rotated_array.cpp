/**
 * Title   : Minimum element in a sorted and rotated array
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array/0
 **/

#include<bits/stdc++.h>
using namespace std;

int findMinumimElement(vector<int> nums) {

    int n = nums.size();

    int low = 0, high = n - 1;

    while (low <= high) {

        if (nums[low] <= nums[high])
            return nums[low];

        int mid = low + (high - low) / 2;
        int prev = (mid - 1 + n) % n;
        int next = (mid + 1) % n;

        if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
            return nums[mid];
        else if (nums[low] <= nums[mid])
            low = mid + 1;
        else if (nums[mid] <= nums[high])
            high = mid - 1;
    }

    return -1;
}

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

        int minElement = findMinumimElement(nums);
        cout << minElement << '\n';
    }

    return 0;
}
