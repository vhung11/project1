//C++ 
#include <bits/stdc++.h> 
using namespace std;

// Định nghĩa một nút trong BST
struct Node {
    int key;
    Node* left;
    Node* right;
};

// Hàm tạo một nút mới với khóa k
Node* createNode(int k) {
    Node* newNode = new Node();
    newNode->key = k;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm chèn một khóa k vào BST
Node* insert(Node* root, int k) {
    // Nếu BST rỗng, tạo một nút mới và trả về
    if (root == NULL) {
        return createNode(k);
    }

    // Nếu khóa k đã tồn tại trong BST, không chèn và trả về root ban đầu
    if (k == root->key) {
        return root;
    }

    // Nếu khóa k nhỏ hơn khóa của root, chèn vào cây con trái
    if (k < root->key) {
        root->left = insert(root->left, k);
    }
    // Nếu khóa k lớn hơn khóa của root, chèn vào cây con phải
    else {
        root->right = insert(root->right, k);
    }

    return root;
}

// Hàm duyệt cây theo thứ tự trước và in ra các khóa đã truy cập
void preOrderTraversal(Node* root) {
    if (root != NULL) {
        cout << root->key << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;
    string command;
    int key;

    while (true) {
        cin >> command;
        if (command == "#") {
            break;
        }
        cin >> key;

        if (command == "insert") {
            root = insert(root, key);
        }
    }

    preOrderTraversal(root);

    return 0;
}
