/**
 * Title   : Decode the pattern
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/decode-the-pattern/0
 **/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string generatePattern(int n) {

        vector<string> row;
        row.emplace_back("1");

        for (int r = 1; r < n; ++r) {

            string prev_row = row[r - 1], curr_row = "";

            int len = prev_row.length(), i = 0;

            while (i < len) {

                int count = 1;
                char curr_char = prev_row[i];

                while (i < len - 1 && prev_row[i + 1] == curr_char) {
                    ++count;
                    ++i;
                }

                curr_row += to_string(count);
                curr_row += curr_char;
                ++i;
            }

            row.emplace_back(curr_row);
        }

        return row[n - 1];
    }
};

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        Solution ob;

        string res = ob.generatePattern(n);
        cout << res << '\n';

    }

    return 0;
}
