#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src; //the source vertex of the edge
    int dest; //destination of the edge
    int weight; // edge weight; 
};

struct Subset {
    int parent;
    int rank;
};

//function to compare edges based on their weights 
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// find operation to get the root of the subset to which i belongs
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

//Union operation to merge two subsets
void Union(Subset subsets[], int x, int y) {
    int xRoot = find(subsets, x);
    int yRoot = find(subsets, y);
    if (subsets[xRoot].rank < subsets[yRoot].rank) {
        subsets[xRoot].parent = yRoot;
    } else if (subsets[xRoot].rank > subsets[yRoot].rank) {
        subsets[yRoot].parent = xRoot;
    } else {
        subsets[yRoot].parent = xRoot;
        subsets[xRoot].rank++;
    }
}

int Kruskal(int N, vector<Edge>& edges) {
    vector<Edge> result;

    Subset* subsets = new Subset[N];
    for (int v = 0; v < N; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    sort(edges.begin(), edges.end(), compareEdges);

    int e = 0, i = 0; // counter for the number of included edges and the current edge index
    while (e < N - 1 && i < edges.size()) {
        Edge nextEdge = edges[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);
        if (x != y) {
            result.push_back(nextEdge);
            Union(subsets, x, y);
            e++;
        }
    }

    int mstWeight = 0;
    for(Edge& edge : result) {
        mstWeight += edge.weight;
    }
    delete[] subsets;
    return mstWeight;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
    int mstWeight = Kruskal(N, edges);
    cout << mstWeight << "\n";

    return 0;
}