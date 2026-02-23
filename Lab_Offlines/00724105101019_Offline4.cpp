#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
};

node *root = NULL;

void insertFirst(int val) {
    node *temp = new node();
    temp->data = val;
    temp->next = root;
    root = temp;
}

void insertLast(int val) {
    if (root == NULL) {
        insertFirst(val);
        return;
    }
    node *temp = new node();
    temp->data = val;
    temp->next = NULL;

    node *curr = root;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
}

void insertByPos(int val, int pos) {
    if (pos == 1) {
        insertFirst(val);
        return;
    }
    node *curr = root;
    for (int i = 1; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }
    if (curr == NULL) {
        cout << "Position out of range" << endl;
    } else {
        node *temp = new node();
        temp->data = val;
        temp->next = curr->next;
        curr->next = temp;
    }
}


void insertByValue(int target, int val) {
    node *curr = root;
    while (curr != NULL && curr->data != target) {
        curr = curr->next;
    }
    if (curr == NULL) {
        cout << "Value " << target << " not found" << endl;
    } else {
        node *temp = new node();
        temp->data = val;
        temp->next = curr->next;
        curr->next = temp;
    }
}


void deleteFirst() {
    if (root == NULL) return;
    node *temp = root;
    root = root->next;
    delete temp;
}


void deleteLast() {
    if (root == NULL) return;
    if (root->next == NULL) {
        delete root;
        root = NULL;
        return;
    }
    node *curr = root;
    node *prev = NULL;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    delete curr;
}


void deleteByPos(int pos) {
    if (root == NULL) return;
    if (pos == 1) {
        deleteFirst();
        return;
    }
    node *curr = root;
    node *prev = NULL;
    for (int i = 1; i < pos && curr != NULL; i++) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        cout << "Position out of range" << endl;
    } else {
        prev->next = curr->next;
        delete curr;
    }
}


void deleteByValue(int val) {
    if (root == NULL) return;
    if (root->data == val) {
        deleteFirst();
        return;
    }
    node *curr = root;
    node *prev = NULL;
    while (curr != NULL && curr->data != val) {
        prev = curr;
        curr = curr->next;
    }
    if (curr != NULL) {
        prev->next = curr->next;
        delete curr;
    } else {
        cout << "Value not found" << endl;
    }
}


void printing() {
    node *curr = root;
    if (curr == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}


void searching(int val) {
    node *curr = root;
    int pos = 1;
    while (curr != NULL) {
        if (curr->data == val) {
            cout << "Found " << val << " at position " << pos << endl;
            return;
        }
        curr = curr->next;
        pos++;
    }
    cout << "Not found" << endl;
}


void last_node() {
    if (root == NULL) return;
    node *curr = root;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    cout << "Last Node: " << curr->data << endl;
}


void previous_of_last_node() {
    if (root == NULL || root->next == NULL) {
        cout << "No previous of last exists" << endl;
        return;
    }
    node *curr = root;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    cout << "Previous of Last: " << curr->data << endl;
}


void list_size() {
    int count = 0;
    node *curr = root;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    cout << "Size: " << count << endl;
}


void reversePrint(node *temp) {
    if (temp == NULL) return;
    reversePrint(temp->next);
    cout << temp->data << " ";
}


int main() {
    insertLast(10);
    insertLast(20);
    insertFirst(5);
    insertByPos(15, 3);
    insertByValue(20, 25);

    cout << "Current List: ";
    printing();

    searching(15);
    list_size();
    last_node();
    previous_of_last_node();

    cout << "Reverse Print: ";
    reversePrint(root);
    cout << endl;

    deleteByPos(2);
    deleteByValue(25);
    deleteFirst();
    deleteLast();

    cout << "Final List: ";
    printing();

    return 0;
}
