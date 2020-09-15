/**
 * Title   : Overlapping Intervals
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/overlapping-intervals/0
 **/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {

    if (intervals.size() <= 1)
        return intervals;

    sort(intervals.begin(), intervals.end());

    vector<vector<int> > res;
    res.emplace_back(intervals[0]);

    for (int i = 0; i < intervals.size(); ++i) {

        if (intervals[i][0] <= res.back()[1])
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        else
            res.emplace_back(intervals[i]);
    }
    return res;
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        vector<vector<int> > intervals(n);

        for (int i = 0; i < n; ++i) {
            int start, end;
            cin >> start >> end;
            intervals[i].emplace_back(start);
            intervals[i].emplace_back(end);
        }

        vector<vector<int> > res = mergeIntervals(intervals);

        for (int i = 0; i < res.size(); ++i) {
            cout << res[i][0] << ' ' << res[i][1] << ' ';
        }

        cout << '\n';

    }

    return 0;
}
