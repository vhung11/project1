//C++ 
#include <bits/stdc++.h> 
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* makeNode(int value) {
    Node* newNode = new Node();
    newNode->value = value;
    newNode->left = newNode->right = 0;
}

Node* insert(int value, Node* root) {
    if (root == nullptr) {
        return makeNode(value);
    }

    if (root->value > value) {
        root->left = insert(value, root->left);
    } else {
        root->right = insert(value, root->right);
    }

    return root;
}

bool search(int value, Node* root) {
    if (root == nullptr) {
        return false;
    }

    if (root->value == value) {
        return true;
    } else if (root->value > value) {
        return search(value, root->left);
    } else {
        return search(value, root->right);
    }
}

int main() 
{ 
    int n;
    cin >> n;
    Node* root = nullptr;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (search(num, root)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
            root = insert(num, root);
        }
    }

    return 0;
}