/**
 * Title   : Merge Without Extra Space
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays/0
 **/

#include<iostream>
using namespace std;

int nextGap(int gap) {
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

int mergeTwoSortedArray(int* arr1, int* arr2, int n, int m) {
    int x = min(n, m);

    for (int i = 0; i < x; i++) {
        if (arr1[n - i - 1] > arr2[i])
            swap(arr1[n - i - 1], arr2[i]);
    }

    for (int gap = nextGap(n); gap > 0; gap = nextGap(gap)) {
        for (int i = 0; i + gap < n; i++)
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);
    }

    for (int gap = nextGap(m); gap > 0; gap = nextGap(gap)) {
        for (int i = 0; i + gap < m; i++)
            if (arr2[i] > arr2[i + gap])
                swap(arr2[i], arr2[i + gap]);
    }
}

int main() {

    int tc;
    cin >> tc;
    while (tc--) {

        int m, n;
        cin >> m >> n;

        int a[m], b[n];

        for (int i = 0; i < m; ++i)
            cin >> a[i];

        for (int i = 0; i < n; ++i)
            cin >> b[i];

        mergeTwoSortedArray(a, b, m, n);

        for (int i = 0; i < m; ++i)
            cout << a[i] << " ";

        for (int i = 0; i < n; ++i)
            cout << b[i] << " ";

        cout << "\n";
    }

    return 0;
}
