/**
 * Title   : Trapping Rain Water
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/trapping-rain-water/0
 **/

#include<iostream>
using namespace std;

int findTrappedRainWater(int height[], int n) {

    if (n == 0 || n == 1)
        return 0;

    int leftPtr = 0, rightPtr = n - 1, leftMax = 0, rightMax = 0, res = 0;

    while (leftPtr < rightPtr) {

        if (height[leftPtr] < height[rightPtr]) {
            if (height[leftPtr] >= leftMax)
                leftMax = height[leftPtr];
            else
                res += leftMax - height[leftPtr];
            ++leftPtr;
        }
        else {
            if (height[rightPtr] >= rightMax)
                rightMax = height[rightPtr];
            else
                res += rightMax - height[rightPtr];
            --rightPtr;
        }
    }
    return res;
}

int main() {
	int T;
	cin >> T;
	while (T--)  {
	    int n;
	    cin >> n;
	    int arr[n];
	    for (int i = 0; i < n; ++i)
	        cin >> arr[i];
	    int res = findTrappedRainWater(arr, n);
	    cout << res << '\n';
	}
	return 0;
}
