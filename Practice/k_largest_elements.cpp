/**
 * Title   : k largest elements
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/reverse-array-in-groups/0
 **/

#include<bits/stdc++.h>
using namespace std;

/* using map

void kLargestElements(int arr[], int n, int k) {

    map<int, int> mp;

    for (int i = 0; i < n; ++i)
        mp[arr[i]]++;

    map<int,int> :: reverse_iterator itr;
    for (itr = mp.rbegin(); itr != mp.rend(); ++itr) {
        for (int i = 1; i <= itr->second; ++i){
            if (k == 0)
                return;
            cout << itr->first << " ";
            --k;
        }
    }

}
*/

void kLargestElements(int arr[], int n, int k) {
    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < k; ++i)
        cout << arr[i] << " ";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        kLargestElements(arr, n, k);
        cout << '\n';
    }
}
