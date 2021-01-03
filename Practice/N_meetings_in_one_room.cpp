/**
 * Title   : N meetings in one room
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

void maxMeetings(int *, int *, int);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        maxMeetings(start, end, n);
        cout << endl;
    }
    return 0;
}// } Driver Code Ends

struct meeting {
    int start_time;
    int end_time;
    int idx;
};

bool comparator(meeting m1, meeting m2) {

    if (m1.end_time < m2.end_time)
        return true;
    else if (m1.end_time > m2.end_time)
        return false;
    else if (m1.idx < m2.idx)
        return true;
    return false;
}

void maxMeetings(int start[], int end[], int n) {

    meeting times[n];

    for (int i = 0; i < n; ++i) {
        times[i].start_time = start[i];
        times[i].end_time = end[i];
        times[i].idx = i + 1;
    }

    sort(times, times + n, comparator);

    vector<int> res;
    res.emplace_back(times[0].idx);

    int last_end_time = times[0].end_time;

    for (int i = 1; i < n; ++i) {

        if (times[i].start_time > last_end_time) {
            res.emplace_back(times[i].idx);
            last_end_time = times[i].end_time;
        }
    }

    for (auto i : res)
        cout << i << ' ';
}
