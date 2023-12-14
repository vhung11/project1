//C++ 
#include <bits/stdc++.h> 
using namespace std;

bool isCorrect(const string& expression) {
    stack<char> brackets;
    
    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            brackets.push(c);
        } else {
            if (brackets.empty()) return false;

            char top = brackets.top();
            brackets.pop();

            if (c == ')' && top != '(' || c == ']' && top != '[' || c == '}' && top != '{') {
                return false;
            }
        }
    }

    return brackets.empty();
}

int main() 
{ 
    string expression;
    getline(cin, expression);

    if (isCorrect(expression)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}