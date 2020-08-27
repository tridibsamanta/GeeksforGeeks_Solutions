/**
 * Title   : Check if frequencies can be equal
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/check-frequencies/0/
 **/

#include<bits/stdc++.h>
using namespace std;

bool checkEqualFrequency(string str) {

    // Count the frequency of occurence of each character
    unordered_map<char, int> freq;

    for (int i = 0; str[i]; ++i) {
        ++freq[str[i]];
    }

    // We find out the number of distinct frequencies present
    set<int> s;

    for (auto it : freq) {
        s.insert(it.second);
    }

    // If there is only one type of frequency, we don't need to remove any character
    if (s.size() == 1)
        return true;

    // If there is more than two types of frequencies, we cant get the desired solution
    // as we can remove atmost one character
    if (s.size() > 2)
        return false;


    // *** Only possiblitity is when we have exactly two types of frequency of occurence ***

    // Count the number of characters, possessing each frequency type
    unordered_map<int, int> hm;

    for (auto it : freq) {
        ++hm[it.second];
    }

    // There has to be one frequency type which is possessed by only one character,
    // then only we can remove that particular character and possibly get our solution
    bool possible = false;
    for (auto it : hm) {
        if (it.second == 1)
            possible = true;
    }

    // If among the two frequencies, one frequency type is possesed by one character
    if (possible) {

        // Check whether difference between both the frequency types is 1 or not
        // as because, we are limited to removing AT MOST ONE character

        unordered_map<int, int> :: iterator it = hm.begin();

        int freq1 = it->first;
        ++it;
        int freq2 = it->first;

        // If difference between both the frequency types is 1, solution possible
        if (abs(freq1 - freq2) == 1)
            return true;
    }

    // The control reaches here if -
    // Among the two frequency types, none is possessed by one character OR
    // Difference between both the frequency types is > 1,
    // hence removing only one character won't result in same frequency of all characters
    return false;

}

int main() {

	int t;
	cin >> t;
	while (t--) {

	    string str;
	    cin >> str;

	    if (checkEqualFrequency(str))
	        cout << 1 << '\n';
	    else
	        cout << 0 << '\n';

	}

	return 0;
}
