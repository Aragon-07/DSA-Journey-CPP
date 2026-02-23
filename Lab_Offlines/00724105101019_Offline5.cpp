#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

int list_size() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    cout << "Size of the list: " << count << endl;
    return count;
}

void insertFirst(int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertLast(int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(int pos, int value) {
    if (pos <= 1) {
        insertFirst(value);
        return;
    }
    Node* newNode = createNode(value);
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr) {
        insertLast(value);
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

void deleteFirst() {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    if (head != nullptr) head->prev = nullptr;
    delete temp;
}

void deleteLast() {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->prev->next = nullptr;
    delete temp;
}

void deleteByValue(int val) {
    if (head == nullptr) return;
    Node* temp = head;
    while (temp != nullptr && temp->data != val) temp = temp->next;
    if (temp == nullptr) return;
    if (temp == head) { deleteFirst(); return; }
    if (temp->next == nullptr) { deleteLast(); return; }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

void printingF() {
    Node* temp = head;
    cout << "Forward: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reversePrint() {
    if (head == nullptr) return;
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    cout << "Reverse: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

void searching(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Value " << value << " found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value not found." << endl;
}

void last_node() {
    if (head == nullptr) return;
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    cout << "Last Node: " << temp->data << endl;
}

void previous_of_last_node() {
    if (head == nullptr || head->next == nullptr) {
        cout << "No node exists before the last node." << endl;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    cout << "Node before last: " << temp->prev->data << endl;
}

int main() {

    insertLast(10);
    insertLast(20);
    insertFirst(5);
    insertAtPosition(3, 15);

    printingF();
    list_size();

    searching(15);
    last_node();
    previous_of_last_node();

    deleteByValue(10);
    printingF();
    reversePrint();

    return 0;
}
