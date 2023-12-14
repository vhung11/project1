#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> queue;
    string query;
    while (cin >> query) {
        if (query == "#") {
            break;
        } else if (query == "PUSH") {
            int num;
            cin >> num;
            queue.push(num);
        } else if (query == "POP") {
            if (queue.empty()) {
                cout << "NULL" << endl;
            } else {
                int front = queue.front();
                queue.pop();
                cout << front << endl;
            }
        }
    }

    return 0;
}