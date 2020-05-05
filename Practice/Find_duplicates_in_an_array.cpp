/**
 * Title   : Find duplicates in an array
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
void printDuplicates(int arr[], int n);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        printDuplicates(a, n);
        cout << endl;
    }
    return 0;
}// } Driver Code Ends

/*Complete the function below*/
void printDuplicates(int a[], int n) {
    int flag = 0;
    for(int i = 0; i < n; ++i)
        a[a[i] % n] += n;
    for(int i = 0; i < n; ++i) {
        if (a[i] / n >= 2) {
            cout << i << " ";
            ++flag;
        }
    }
    if (flag == 0)
        cout << "-1";
}
