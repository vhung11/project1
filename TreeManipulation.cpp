#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id;
    vector<Node*> children;

    Node(int _id) : id(_id) {}
};

unordered_map<int, Node*> nodes;

void PreOrder(Node* node) {
    if (node == nullptr) return;
    cout << node->id << " ";
    for (Node* child : node->children) {
        PreOrder(child);
    }
}

void InOrder(Node* node) {
    if (node == nullptr) return;
    if (!node->children.empty()) {
        InOrder(node->children[0]);
    }
    cout << node->id << " ";
    for (int i = 1; i < node->children.size(); i++) {
        InOrder(node->children[i]);
    }
}

void PostOrder(Node* node) {
    if (node == nullptr) return;
    for (Node* child : node->children) {
        PostOrder(child);
    }
    cout << node->id << " ";
}

void MakeRoot(int id) {
    nodes[id] = new Node(id);
}

void Insert(int u, int v) {
    if (nodes.find(u) != nodes.end() || nodes.find(v) == nodes.end()) return;

    Node* newNode = new Node(u);
    Node* parent = nodes[v];
    parent->children.push_back(newNode);
    nodes[u] = newNode;
}

int main() {
    string action;
    while (cin >> action) {
        if (action == "MakeRoot") {
            int u;
            cin >> u;
            MakeRoot(u);
        } else if (action == "Insert") {
            int u, v;
            cin >> u >> v;
            Insert(u, v);
        } else if (action == "PreOrder") {
            PreOrder(nodes[10]);
            cout << endl;
        } else if (action == "InOrder") {
            InOrder(nodes[10]);
            cout << endl;
        } else if (action == "PostOrder") {
            PostOrder(nodes[10]);
            cout << endl;
        } else if (action == "*") {
            break;
        }
    }

    return 0;
}