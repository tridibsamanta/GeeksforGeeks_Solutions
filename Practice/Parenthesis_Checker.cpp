/**
 * Title   : Parenthesis Checker
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/parenthesis-checker/0
 **/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool CheckPair(char opening, char closing) {
    if(opening == '(' && closing == ')')
        return true;
    else if(opening == '{' && closing == '}')
        return true;
    else if(opening == '[' && closing == ']')
        return true;
    else
        return false;
}

bool CheckBalancedParenthesis(string exp) {
    stack<char> S;
    for(int i=0;i<exp.length();i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            S.push(exp[i]);
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            if(S.empty() || !CheckPair(S.top(),exp[i]))
                return false;
            else
                S.pop();
        }
    }
    return (S.empty()?true:false);
}

int main() {
    int T;
    cin>>T;
    while(T--) {
    string s;
    cin>>s;
    if(CheckBalancedParenthesis(s))
        cout<<"balanced"<<endl;
    else
        cout<<"not balanced"<<endl;
    }
    return 0;
}
