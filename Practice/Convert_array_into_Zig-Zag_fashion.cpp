/**
 * Title   : Convert array into Zig-Zag fashion
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion/0
 **/

#include<bits/stdc++.h>
using namespace std;

void convertZigZag(int a[], int n) {

    for (int i = 0; i < n - 1; ++i) {
        if (i & 1) {
            if (a[i] < a[i + 1])
                swap(a[i], a[i + 1]);
        }
        else {
            if (a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
        }
    }

}

int main()
 {
	int t;
	cin >> t;
	while (t--) {

	    int n;
	    cin >> n;

	    int arr[n];
	    for (int i = 0; i < n; ++i)
	    cin >> arr[i];

	    convertZigZag(arr, n);

	    for (int i = 0; i < n; ++i)
	        cout << arr[i] << ' ';

	   cout << '\n';

	}
	return 0;
}
