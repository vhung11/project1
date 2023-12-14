#include <iostream>
#include <vector>

using namespace std;

bool isHamiltonianGraph(int n, vector<pair<int, int>>& edges) {
    // Check if the graph has at least 3 vertices
    if (n < 3) {
        return false;
    }

    // Calculate the degree of each vertex
    vector<int> degrees(n + 1, 0);
    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        degrees[u]++;
        degrees[v]++;
    }

    // Check if every vertex has degree at least n/2
    for (int degree : degrees) {
        if (degree < n / 2) {
            return false;
        }
    }

    return true;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> edges;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        bool result = isHamiltonianGraph(n, edges);
        cout << (result ? 1 : 0) << endl;
    }

    return 0;
}