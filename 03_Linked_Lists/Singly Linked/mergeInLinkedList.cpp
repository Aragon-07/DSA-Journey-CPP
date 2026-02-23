#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int v) {
        value = v;
        next = NULL;
    };
};

void traverse(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->value << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtEnd(Node* &head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to merge two sorted lists
Node* mergeLists(Node* head1, Node* head2) {
    // Create a dummy node to start the list
    Node* dummy = new Node(-1);
    Node* temp = dummy;

    while (head1 != NULL && head2 != NULL) {
        if (head1->value <= head2->value) {
            temp->next = head1;
            head1 = head1->next;
        } else {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }

    // If one list is longer than the other, attach the rest
    if (head1 != NULL) {
        temp->next = head1;
    } else {
        temp->next = head2;
    }

    Node* mergedHead = dummy->next;
    delete dummy; // Clean up the dummy node
    return mergedHead;
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    // List 1 (Sorted): 1 -> 3 -> 5
    insertAtEnd(head1, 1);
    insertAtEnd(head1, 3);
    insertAtEnd(head1, 5);

    // List 2 (Sorted): 2 -> 4 -> 6
    insertAtEnd(head2, 2);
    insertAtEnd(head2, 4);
    insertAtEnd(head2, 6);

    cout << "List 1: ";
    traverse(head1);
    cout << "List 2: ";
    traverse(head2);

    Node* mergedHead = mergeLists(head1, head2);

    cout << "Merged List: ";
    traverse(mergedHead);

    return 0;
}
