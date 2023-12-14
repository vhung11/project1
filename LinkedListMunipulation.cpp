#include <iostream>
#include <sstream>
#include <string>

struct Node {
    int key;
    Node* next;

    Node(int k) : key(k), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    bool contains(int k) {
        Node* current = head;
        
        while (current != nullptr) {
            if (current->key == k) {
                return true;
            }
            current = current->next;
        }

        return false;
    }

    void addLast(int k) {
        if (contains(k)) return; 

        Node* newNode = new Node(k);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void addFirst(int k) {
        if (contains(k)) return; 

        Node* newNode = new Node(k);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                if (current->key == k) return;
                current = current->next;
            }
            newNode->next = head;
            head = newNode;
        }
    }

    void addAfter(int u, int v) {
        if (contains(u)) return;

        Node* newNode = new Node(u);

        Node* current = head;
        while (current != nullptr) {
            if (current->key == v) {
                newNode->next = current->next;
                current->next = newNode;
                break;
            }
            current = current->next;
        }
    }

    void addBefore(int u, int v) {
        if (contains(u)) return;

        Node* newNode = new Node(u);

        if (head->key == v) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* prev = nullptr;
            Node* current = head;
            while (current != nullptr) {
                if (current->key == v) {
                    newNode->next = current;
                    prev->next = newNode;
                    break;
                }
                prev = current;
                current = current->next;
            }
        }
    }

    void remove(int k) {
        if (head == nullptr)
            return;

        if (head->key == k) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = nullptr;
        Node* current = head;
        while (current != nullptr) {
            if (current->key == k) {
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void reverse() {
        if (head == nullptr || head->next == nullptr)
            return;

        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    void printKeys() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->key << " ";
            current = current->next;
        }
    }
};

int main() {
    int n;
    std::cin >> n;

    LinkedList list;

    for (int i = 0; i < n; i++) {
        int key;
        std::cin >> key;
        list.addLast(key);
    }

    std::cin.ignore();

    std::string command;
    while (getline(std::cin, command)) {
        if (command == "#")
            break;

        std::istringstream iss(command);
        std::string operation;
        iss >> operation;

        if (operation == "addlast") {
            int k;
            iss >> k;
            list.addLast(k);
        } else if (operation == "addfirst") {
            int k;
            iss >> k;
            list.addFirst(k);
        } else if (operation == "addafter") {
            int u, v;
            iss >> u >> v;
            list.addAfter(u, v);
        } else if (operation == "addbefore") {
            int u, v;
            iss >> u >> v;
            list.addBefore(u, v);
        } else if (operation == "remove") {
            int k;
            iss >> k;
            list.remove(k);
        } else if (operation == "reverse") {
            list.reverse();
        }
    }

    list.printKeys();

    return 0;
}