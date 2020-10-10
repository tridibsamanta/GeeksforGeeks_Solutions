/**
 * Title   : First and last occurrences of X
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x/0
 **/

#include<bits/stdc++.h>
using namespace std;

int findFirstOccurrenceIndex(vector<int> &nums, int target) {

    int n = nums.size();

    int low = 0, high = n - 1, idx = -1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            idx = mid;
            high = mid - 1;
        }
        else if (nums[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return idx;
}

int findLastOccurrenceIndex(vector<int> &nums, int target) {

    int n = nums.size();

    int low = 0, high = n - 1, idx = -1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            idx = mid;
            low = mid + 1;
        }
        else if (nums[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return idx;
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        int x;
        cin >> x;

        vector<int> nums;

        for (int i = 0; i < n; ++i) {
            int element;
            cin >> element;
            nums.emplace_back(element);
        }

        int firstOccIdx = findFirstOccurrenceIndex(nums, x);

        if (firstOccIdx == -1)
            cout << -1 << '\n';
        else {
            int lastOccIdx = findLastOccurrenceIndex(nums, x);
            cout << firstOccIdx << ' ' << lastOccIdx << '\n';
        }

    }

    return 0;
}
