#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void addToEnd(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
}

void addToBegin(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void addAfterKey(Node*& head, int key, int value) {
    Node* current = head;

    while (current != nullptr && current->data != key) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Key was not found." << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = current->next;
    current->next = newNode;
}

void removeFromBegin(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void removeFromEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;

    while (current->next->next != nullptr) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
}

void removeByKey(Node*& head, int key) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    while (head != nullptr && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->next->data == key) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else {
            current = current->next;
        }
    }
}

void showList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "List: ";

    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}

void createList(Node*& head) {
    int count;
    int value;

    cout << "Enter number of elements: ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        cout << "Enter number: ";
        cin >> value;
        addToEnd(head, value);
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
    Node* head = nullptr;
    int choice;
    int value;
    int key;

    do {
        cout << "\nMenu:" << endl;
        cout << "1 - Create list" << endl;
        cout << "2 - Show list" << endl;
        cout << "3 - Remove from beginning" << endl;
        cout << "4 - Remove by key" << endl;
        cout << "5 - Remove from end" << endl;
        cout << "6 - Add to beginning" << endl;
        cout << "7 - Add to end" << endl;
        cout << "8 - Add after key" << endl;
        cout << "9 - Exit" << endl;
        cout << "Choose option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            freeList(head);
            createList(head);
            break;

        case 2:
            showList(head);
            break;

        case 3:
            removeFromBegin(head);
            break;

        case 4:
            cout << "Enter key to remove: ";
            cin >> key;
            removeByKey(head, key);
            break;

        case 5:
            removeFromEnd(head);
            break;

        case 6:
            cout << "Enter value: ";
            cin >> value;
            addToBegin(head, value);
            break;

        case 7:
            cout << "Enter value: ";
            cin >> value;
            addToEnd(head, value);
            break;

        case 8:
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter value: ";
            cin >> value;
            addAfterKey(head, key, value);
            break;

        case 9:
            freeList(head);
            cout << "Program finished." << endl;
            break;

        default:
            cout << "Incorrect option." << endl;
            break;
        }

    } while (choice != 9);

    return 0;
}
