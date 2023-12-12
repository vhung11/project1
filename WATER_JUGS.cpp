#include <bits/stdc++.h>
using namespace std;

struct State {
    int jugA;
    int jugB;
    int steps;

    State(int a, int b, int s) : jugA(a), jugB(b), steps(s) {}
};

int solve(int a, int b, int c) {
    if (c > max(a, b) || c % gcd(a, b) != 0)
        return -1;

    queue<State> q;
    set<pair<int, int>> visited;

    q.emplace(0, 0, 0);
    visited.insert({0, 0});

    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        if (curr.jugA == c || curr.jugB == c)
            return curr.steps;

        // Fill jug A
        if (visited.find({a, curr.jugB}) == visited.end()) {
            q.emplace(a, curr.jugB, curr.steps + 1);
            visited.insert({a, curr.jugB});
        }

        // Fill jug B
        if (visited.find({curr.jugA, b}) == visited.end()) {
            q.emplace(curr.jugA, b, curr.steps + 1);
            visited.insert({curr.jugA, b});
        }

        // Pour from jug A to jug B
        int pourAmount = min(curr.jugA, b - curr.jugB);
        if (visited.find({curr.jugA - pourAmount, curr.jugB + pourAmount}) == visited.end()) {
            q.emplace(curr.jugA - pourAmount, curr.jugB + pourAmount, curr.steps + 1);
            visited.insert({curr.jugA - pourAmount, curr.jugB + pourAmount});
        }

        // Pour from jug B to jug A
        pourAmount = min(a - curr.jugA, curr.jugB);
        if (visited.find({curr.jugA + pourAmount, curr.jugB - pourAmount}) == visited.end()) {
            q.emplace(curr.jugA + pourAmount, curr.jugB - pourAmount, curr.steps + 1);
            visited.insert({curr.jugA + pourAmount, curr.jugB - pourAmount});
        }

        // Empty jug A
        if (visited.find({0, curr.jugB}) == visited.end()) {
            q.emplace(0, curr.jugB, curr.steps + 1);
            visited.insert({0, curr.jugB});
        }

        // Empty jug B
        if (visited.find({curr.jugA, 0}) == visited.end()) {
            q.emplace(curr.jugA, 0, curr.steps + 1);
            visited.insert({curr.jugA, 0});
        }
    }

    return -1; // No solution found
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int steps = solve(a, b, c);
    cout << steps << endl;

    return 0;
}