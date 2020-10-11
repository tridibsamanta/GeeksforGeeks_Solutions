/**
 * Title   : Search in a Rotated Array
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array/0
 **/

#include<bits/stdc++.h>
using namespace std;

int findElement(vector<int> &nums, int target) {

    int low = 0, high = nums.size() - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[mid] <= nums[high]) {
            if (target > nums[mid] && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
        else if (nums[low] <= nums[mid]) {
            if (target >= nums[low] && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
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

        int k;
        cin >> k;

        int index = findElement(nums, k);
        cout << index << '\n';
    }

    return 0;
}
