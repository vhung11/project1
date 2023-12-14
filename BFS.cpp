#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void bfs(const vector<set<int>>& graph, int start) {
    set<int> visited;
    queue<int> q;
    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Tạo đồ thị rỗng
    vector<set<int>> graph(n + 1);

    // Đọc các cạnh và xây dựng đồ thị
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }

    // Thực hiện BFS bắt đầu từ đỉnh 1
    bfs(graph, 1);

    return 0;
}