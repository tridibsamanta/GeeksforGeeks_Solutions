/**
 * Title   : Number of occurrence
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1
 **/

// { Driver Code Starts



#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


//User function template for C++
class Solution{
public:

    int findFirstOccurrenceIndex(vector<int> &nums, int target) {

        int low = 0, high = nums.size() - 1, idx = -1;

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

    int findLastOccurrenceIndex(vector<int> &nums, int target, int firstOccIdx) {

        int low = firstOccIdx, high = nums.size() - 1, idx = -1;

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

	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {

	    vector<int> nums(arr, arr + n);

	    int firstOccIdx = findFirstOccurrenceIndex(nums, x);

	    if (firstOccIdx == -1)
	        return 0;
	    else {
	        return (findLastOccurrenceIndex(nums, x, firstOccIdx) - firstOccIdx) + 1;
	    }

	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
