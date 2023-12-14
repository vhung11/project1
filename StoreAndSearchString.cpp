#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<string> database;

    string key;
    while(1) {
        cin >> key;
        if (key == "*") {
            break;
        } 
        database.insert(key);
    }

    string cmd, k;
    while(1) {
        cin >> cmd >> k;
        if (cmd == "***") {
            break;
        }
        if (cmd == "find") {
            int result = database.count(k);
            cout << result << endl;
        } else if (cmd == "insert") {
            int result = database.insert(k).second;
            cout << result << endl;
        }
    }

    return 0;
}