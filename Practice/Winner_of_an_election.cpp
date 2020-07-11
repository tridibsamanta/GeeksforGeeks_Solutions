/**
 * Title   : Winner of an election
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names/0
 **/

#include<bits/stdc++.h>
using namespace std;

void findWinner(vector<string> str) {

    map<string, int> voteCount;
    for (auto s = str.begin(); s != str.end(); ++s)
        ++voteCount[*s];

    string winner = "";
    int maxVotes = INT_MIN;

    for (auto itr = voteCount.begin(); itr != voteCount.end(); ++itr) {

        if (itr->second > maxVotes) {
            maxVotes = itr->second;
            winner = itr->first;
        }
        else if (itr->second == maxVotes && winner > itr->first)
            winner = itr->first;
    }

    cout << winner << ' ' << maxVotes << '\n';
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        vector<string> str;

        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            str.emplace_back(s);
        }

        findWinner(str);

    }

    return 0;
}
