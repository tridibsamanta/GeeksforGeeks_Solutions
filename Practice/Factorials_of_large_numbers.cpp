/**
 * Title   : Factorials of large numbers
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers/0
 **/

#include<bits/stdc++.h>
using namespace std;

// #define MAX_DIGITS 100000

// void multiply(int k, int res[], int& res_size) {

//     int carry = 0;

//     for (int i = 0; i < res_size; ++i) {
//         int prod = res[i] * k + carry;
//         res[i] = prod % 10;
//         carry = prod / 10;
//     }

//     while (carry) {
//         res[res_size] = carry % 10;
//         carry /= 10;
//         res_size++;
//     }
// }

// void getFactorial(int n) {

//     int res[MAX_DIGITS];
//     res[0] = 1;

//     int res_size = 1;

//     for (int i = 2; i <= n; ++i) {
//         multiply(i, res, res_size);
//     }

//     // Print res[] in reverse
//     for (int i = res_size - 1; i >= 0; --i)
//         cout << res[i];
// }

void getFactorial(int n) {

    vector<int> res(1, 1);

    for (int k = 2; k <= n; ++k) {

        int carry = 0;
        for (int i = 0; i < res.size(); ++i) {
            int prod = res[i] * k + carry;
            res[i] = prod % 10;
            carry = prod / 10;
        }

        while (carry) {
            res.emplace_back(carry % 10);
            carry /= 10;
        }
    }

    for (int i = res.size() - 1; i >= 0; --i)
        cout << res[i];
}

int main() {

	int t;
	cin >> t;
	while(t--) {

	    int n;
	    cin >> n;

	    getFactorial(n);
	    cout << '\n';
	}

	return 0;
}
