/**
 * Title   : Infix to Postfix
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/infix-to-postfix/0
 **/

#include<bits/stdc++.h>
using namespace std;

int prec(char ch) {
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string exp) {
    stack<char> s;
    string res;
    for (int i = 0; i < exp.length(); ++i) {
        if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z'))
            res += exp[i];
        else if (exp[i] == '(')
            s.push('(');
        else if (exp[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                res += s.top();
                s.pop();
            }
            if (s.top() == '(')
                s.pop();
        }
        else {
            while (!s.empty() && prec(exp[i]) <= prec(s.top())) {
                res += s.top();
                s.pop();
            }
            s.push(exp[i]);
        }
    }
    while (!s.empty()) {
        res += s.top();
        s.pop();
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string exp;
        cin >> exp;
        string postfix = infixToPostfix(exp);
        cout << postfix << '\n';
    }
    return 0;
}
