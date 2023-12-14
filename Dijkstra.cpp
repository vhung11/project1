#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii;  // pair of node and distance

const int INF = numeric_limits<int>::max();

vector<int> shortestPath(int n, int m, const vector<vector<pair<int, int>>>& graph, int s, int t) {
    vector<int> dist(n + 1, INF);
    dist[s] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (cost > dist[u])
            continue;

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            int newDist = dist[u] + weight;
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int s, t;
    cin >> s >> t;

    vector<int> dist = shortestPath(n, m, graph, s, t);

    if (dist[t] == INF)
        cout << -1 << endl;
    else
        cout << dist[t] << endl;

    return 0;
}