#include <bits/stdc++.h>
using namespace std;

vector <string> parents;
vector <string> indexParent[9999];

int checkParent(string parent) {
    for (int i = 0; i < parents.size(); ++i) {
        if (parents[i] == parent) return i;
    }
    return 9999;
}

int indexRoot = 0;
string findRoot() {
    vector <string> v;
    for (int i = 0; i < parents.size(); ++i) {
        for (int j = 0; j < indexParent[i].size(); ++j) {
            v.push_back(indexParent[i][j]);
        }
    }
    for (int i = 0; i < parents.size(); ++i) {
        string tmp = parents[i];
        for (int j = 0; j < v.size(); ++j) {
            if (tmp == v[j]) {
                tmp = "123";
                break;
            }
        }
        if (tmp != "123") {
            indexRoot = i;
            return tmp;
        }
    }
    return "Bao";
}

struct node {
    string name;
    node* leftChild;
    node* rightSibling;
};

node* createNode(string name) {
    node* tmp = (node*)malloc(sizeof(node));
    tmp->name = name;
    tmp->leftChild = nullptr;
    tmp->rightSibling = nullptr;
    return tmp;
}

node* root = createNode("Bao");

node* find(string name) {
    queue <node*> q;
    q.push(root);
    while (!q.empty()) {
        node* tmp = q.front(); q.pop();
        if (tmp->name == name) return tmp;
        if (tmp->rightSibling != nullptr) q.push(tmp->rightSibling);
        if (tmp->leftChild != nullptr) q.push(tmp->leftChild);
    }
    return nullptr;
}

void insert(string child, string parent) {
    node* f = find(parent);
    node* tmp = createNode(child);    
    if (f->leftChild == nullptr) f->leftChild = tmp;
    else {
        node* it = f->leftChild;
        while (it->rightSibling != nullptr) {
            it = it->rightSibling; 
        }
        it->rightSibling = tmp;
    }
}

void buildFamilyTree() {
    queue <node*> q;
    q.push(root);
    while (!q.empty()) {
        node* tmp = q.front(); q.pop();
        string parent = tmp->name;
        for (int i = 0; i < parents.size(); ++i) {
            if (parents[i] == parent) {
                for (int j = 0; j < indexParent[i].size(); ++j) {
                    insert(indexParent[i][j], parent);
                    for (int k = 0; k < parents.size(); ++k) {
                        if (parents[k] == indexParent[i][j]) {
                            q.push(createNode(parents[k]));
                        }
                    }
                }
                break;
            }
        }
    }
}

int descendants(string name) {
    queue <node*> q;
    q.push(find(name));
    int cnt = -1;
    while (!q.empty()) {
        node* tmp = q.front(); q.pop(); ++cnt;
        if (tmp->leftChild != nullptr) {
            q.push(tmp->leftChild);
            node* rs = tmp->leftChild->rightSibling;
            while (rs != nullptr) {
                q.push(rs);
                rs = rs->rightSibling;
            }
        }
    }
    return cnt;
}

int generation(string name) {
    queue <node*> q;
    q.push(find(name));
    map <string, int> g;
    g[name] = -1;
    vector <int> v;
    while (!q.empty()) {
        node* tmp = q.front(); q.pop();
        int nextG = g[tmp->name] + 1;
        v.push_back(nextG);
        if (tmp->leftChild != nullptr) {
            q.push(tmp->leftChild);
            g[tmp->leftChild->name] = nextG;
            node* rs = tmp->leftChild->rightSibling;
            while (rs != nullptr) {
                q.push(rs);
                g[rs->name] = nextG;
                rs = rs->rightSibling;
            }
        }
    }
    return v.back();
}
 
int main() {
    string c; cin >> c;
    while (c != "***") {
        string p; cin >> p;
        int index = checkParent(p);
        if (index != 9999) indexParent[index].push_back(c);
        else {
            parents.push_back(p);
            indexParent[parents.size() - 1].push_back(c);
        }
        cin >> c;
    }
    root->name = parents[indexRoot];
    buildFamilyTree();
    string query; cin >> query;
    while (query != "***") {
        string name; cin >> name;
        if (query == "descendants") {
            cout << descendants(name) << endl;
        } else if (query == "generation") {
            cout << generation(name) << endl;
        }   
        cin >> query;
    }
    return 0;
}