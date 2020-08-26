/**
 * Title   : Search in a matrix
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/search-in-a-matrix/0
 **/

#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int> >& matrix, int target) {

    if (matrix.size() == 0)
        return false;

    int r = matrix.size();
    int c = matrix[0].size();

    int rIdx = 0, cIdx = c - 1;

    while (rIdx < r && cIdx >= 0) {

        if (matrix[rIdx][cIdx] == target)
            return true;

        if (target < matrix[rIdx][cIdx])
            --cIdx;
        else
            ++rIdx;

    }

    return false;
}

int main() {

	int t;
	cin >> t;
	while (t--) {

	    int n, m;
	    cin >> n >> m;

	    vector<vector<int> > matrix(n);

	    for (int i = 0; i < n; ++i) {
	        for (int j = 0; j < m; ++j) {
	            int element;
	            cin >> element;
	            matrix[i].emplace_back(element);
	        }
	    }

	    int target;
	    cin >> target;

	    if (searchMatrix(matrix, target))
	        cout << 1 << '\n';
	    else
	        cout << 0 << '\n';

	}

	return 0;
}
