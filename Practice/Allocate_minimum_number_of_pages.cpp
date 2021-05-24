/**
 * Title   : Allocate minimum number of pages
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
 **/

// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    bool isPossible(int pages, int books[], int n, int k) {

        int curr_k = 1, rem_pages = pages;

        for (int i = 0; i < n; ++i) {
            if (books[i] > rem_pages) {
                if (++curr_k > k)
                    return false;

                rem_pages = pages - books[i];
            }
            else {
                rem_pages -= books[i];
            }
        }

        return curr_k <= k;
    }

    int findPagesUtil(int lo, int hi, int books[], int n, int k) {

        int minPages = hi;

        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            if (isPossible(mid, books, n, k)) {
                minPages = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        return minPages;
    }

    int findPages(int arr[], int n, int m) {

        if (m > n)
            return -1;

        int lo = INT_MIN, hi = 0;

        for (int i = 0; i < n; ++i) {
            lo = max(lo, arr[i]);
            hi += arr[i];
        }

    return findPagesUtil(lo, hi, arr, n, m);
    }
};

// T.C. - O(N*log k)
// where, N -> number of books and k -> sum of pages of all books
// S.C. - O(1)

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends
