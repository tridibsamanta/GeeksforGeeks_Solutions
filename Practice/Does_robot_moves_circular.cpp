/**
 * Title   : Does robot moves circular
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/does-robot-moves-circular0414/1
 **/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string isCircular(string path);

int main(){
    int t;
    cin >> t;
    while(t--){
        string path;
        cin >> path;
        cout << isCircular(path) << endl;
    }
return 0;
}// } Driver Code Ends


string isCircular(string path){

    // 1 -> North, 2 -> East, 3 -> South, 4 -> West

    int x = 0, y = 0;
    int face = 1;

    for (int i = 0; i < path.length(); ++i) {
        if (path[i] == 'G') {
            if (face == 1)
                ++y;
            else if (face == 2)
                ++x;
            else if (face == 3)
                --y;
            else if (face == 4)
                --x;
        }
        else if (path[i] == 'R') {
            face = (face == 4) ? 1 : ++face;
        }
        else {
            face = (face == 1) ? 4 : --face;
        }
    }

    if (x == 0 && y == 0)
        return "Circular";
    else
        return "Not Circular";
}

// T.C. - O(n), n -> length of the string
// S.C. - O(1)
