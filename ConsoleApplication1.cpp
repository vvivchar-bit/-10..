#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* createList() {
    Node* head = nullptr;
    Node* tail = nullptr;

    int count;
    cout << "Enter number of elements: ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        Node* newNode = new Node;

        cout << "Enter surname: ";
        cin >> newNode->data;

        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void showList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "\nSingly linked list:" << endl;

    Node* current = head;

    while (current != nullptr) {
        cout << current->data << endl;
        current = current->next;
    }
}

void freeList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = createList();

    showList(head);

    freeList(head);

    return 0;
}