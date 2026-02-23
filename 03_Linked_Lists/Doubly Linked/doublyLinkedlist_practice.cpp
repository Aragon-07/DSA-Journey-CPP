#include<bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* prev;
    Node* next;

    Node(int v) {
        value = v;
        next = NULL;
        prev = NULL;
    }
};

void forwardTraversal(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->value << " <-> ";
        temp = temp->next;
    } cout << "NULL" << endl;
}

void backwardTraversal(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        cout << temp->value << " <-> ";
        temp = temp->prev;
    } cout << "NULL" << endl;
}

void insertAtHead(Node* &head, int val) {
    Node* newNode = new Node(val);
    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
}

void insertAtEnd(Node* &head, int val) {
    if (head == NULL) {
        insertAtHead(head, val);
        return;
    }
    Node* newNode = new Node(val);
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtMiddle(Node* &head, int val, int position) {
    if (position == 1) {
        insertAtHead(head, val);
        return;
    }
    Node* newNode = new Node(val);
    Node* prevNode = head;
    int count = 1;
    while (count < position - 1) {
        prevNode = prevNode->next;
        count++;
    }

    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
}

void deleteAtHead(Node* &head) {
    if (head == NULL) return;

    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    delete temp;
}

void deleteAtEnd(Node* &head) {
    if (head == NULL) return;
    if (head->next == NULL) {
        deleteAtHead(head);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    Node* secondLastNode = temp->prev;
    secondLastNode->next = NULL;
    delete temp;
}

void deleteAtMiddle(Node* &head, int position) {
    if (position == 1) {
        deleteAtHead(head);
        return;
    }
    Node* prevNode = head;
    int count = 1;
    while (count < position - 1) {
        prevNode = prevNode->next;
        count++;
    }

    Node* current = prevNode->next;
    prevNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = prevNode;
    }
    delete current;
}

int main() {
    Node* head = NULL;

    insertAtHead(head, 2);
    insertAtHead(head, 1);
    forwardTraversal(head); // 1 <-> 2 <-> NULL

    insertAtEnd(head, 3);
    forwardTraversal(head); // 1 <-> 2 <-> 3 <-> NULL

    insertAtMiddle(head, 5, 2);
    forwardTraversal(head); // 1 <-> 5 <-> 2 <-> 3 <-> NULL

    deleteAtMiddle(head, 2);
    forwardTraversal(head); // 1 <-> 2 <-> 3 <-> NULL

    backwardTraversal(head); // 3 <-> 2 <-> 1 <-> NULL

    return 0;
}
