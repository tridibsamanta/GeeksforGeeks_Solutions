/**
 * Title   : Jumping Caterpillars
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/jumping-caterpillars/0
 **/

#include<bits/stdc++.h>
using namespace std;

int findUneatenLeaves(int cp[], int cp_count, int leaf_count) {

    vector<bool> eaten(leaf_count + 1, false);

    for (int i = 0; i < cp_count; ++i) {
        if (eaten[cp[i]] == false) {
            for (int j = cp[i]; j <= leaf_count; j += cp[i])
                eaten[j] = true;
        }
    }

    int uneaten = 0;
    for (int i = 1; i <= leaf_count; ++i) {
        if (!eaten[i])
            ++uneaten;
    }

    return uneaten;
}

int main() {

    int t;
    cin >> t;
    while(t--) {

        int n; // No. of leaves
        cin >> n;

        int k; // No. of caterpillars
        cin >> k;

        int cp[k]; // Jump multiples
        for (int i = 0; i < k; ++i)
            cin >> cp[i];

        int uneaten = findUneatenLeaves(cp, k, n);
        cout << uneaten << '\n';
    }

    return 0;
}

