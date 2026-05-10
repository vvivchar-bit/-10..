#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
};

void addToEnd(Node*& head, Node*& tail, const string& value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void createList(Node*& head, Node*& tail) {
    int count;
    string value;

    cout << "Enter number of elements: ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        cout << "Enter surname: ";
        cin >> value;
        addToEnd(head, tail, value);
    }
}

void showFromBegin(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "\nList from beginning:" << endl;

    Node* current = head;

    while (current != nullptr) {
        cout << current->data << endl;
        current = current->next;
    }
}

void showFromEnd(Node* tail) {
    if (tail == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "\nList from end:" << endl;

    Node* current = tail;

    while (current != nullptr) {
        cout << current->data << endl;
        current = current->prev;
    }
}

void removeByValue(Node*& head, Node*& tail, const string& value) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data == value) {
            Node* nodeToDelete = current;

            if (nodeToDelete == head) {
                head = head->next;

                if (head != nullptr) {
                    head->prev = nullptr;
                }
                else {
                    tail = nullptr;
                }

                current = head;
            }
            else if (nodeToDelete == tail) {
                tail = tail->prev;

                if (tail != nullptr) {
                    tail->next = nullptr;
                }

                current = nullptr;
            }
            else {
                nodeToDelete->prev->next = nodeToDelete->next;
                nodeToDelete->next->prev = nodeToDelete->prev;
                current = nodeToDelete->next;
            }

            delete nodeToDelete;
            cout << "Element was removed." << endl;
            return;
        }

        current = current->next;
    }

    cout << "Element was not found." << endl;
}

void freeList(Node*& head, Node*& tail) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    tail = nullptr;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    string valueToRemove;

    createList(head, tail);

    showFromBegin(head);
    showFromEnd(tail);

    cout << "\nEnter surname to remove: ";
    cin >> valueToRemove;

    removeByValue(head, tail, valueToRemove);

    showFromBegin(head);

    freeList(head, tail);

    return 0;
}
