#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> stack;
    string query;
    while (cin >> query) {
        if (query == "#") {
            break;
        } else if (query == "PUSH") {
            int num;
            cin >> num;
            stack.push(num);
        } else if (query == "POP") {
            if (stack.empty()) {
                cout << "NULL" << endl;
            } else {
                int top = stack.top();
                stack.pop();
                cout << top << endl;
            }
        }
    }

    return 0;
}