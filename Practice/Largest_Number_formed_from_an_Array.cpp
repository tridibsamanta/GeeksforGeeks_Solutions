/**
 * Title   : Largest Number formed from an Array
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array/0
 **/

#include<bits/stdc++.h>
using namespace std;

int myCompare(string s1, string s2) {

    string s1s2 = s1.append(s2);
    string s2s1 = s2.append(s1);

    return s1s2.compare(s2s1) > 0 ? 1 : 0;
}

void findBiggestNumber(vector<string> arr) {

    sort(arr.begin(), arr.end(), myCompare);

    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i];
}

int main() {

    int t;
    cin >> t;
    while (t--) {

    int n;
    cin >> n;
    vector<string> arr(n, "");
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    findBiggestNumber(arr);
    cout << '\n';

    }
    return 0;
}
