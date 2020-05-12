/**
 * Title   : Evaluation of Postfix Expression
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression/0
 **/

#include<iostream>
#include<stack>
#include<ios>
#include<limits>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> S;
    for(int i = 0; i < exp.length(); ++i) {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            int result = 0;
            int operand2 = S.top(); S.pop();
            int operand1 = S.top(); S.pop();
            if (exp[i] == '+')
                result = operand1 + operand2;
            else if (exp[i] == '-')
                result = operand1 - operand2;
            else if (exp[i] == '*')
                result = operand1 * operand2;
            else if (exp[i] == '/')
                result = operand1 / operand2;
            S.push(result);
        }
        else if (exp[i] >= '0' && exp[i] <= '9')
            S.push(exp[i] - '0');
    }
    return S.top();
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        string exp;
        cin >> exp;
        int res = evaluatePostfix(exp);
        cout << res << '\n';
    }
    return 0;
}
