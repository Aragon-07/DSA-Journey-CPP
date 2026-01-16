#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node* next;

    Node(int v){
        value=v;
        next=NULL;
        };
};
void traverse(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->value<<"->";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}

void insertAtHead(Node* &head,int val){
    Node* newNode= new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node* &head,int val){
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    Node* newNode= new Node(val);
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newNode;
}

void deleteAlternateNode(Node* &head){
    Node* temp = head;
    while(temp!=NULL&&temp->next!=NULL){
        Node* deleteNode = temp->next;
        temp->next=temp->next->next;
        temp=temp->next;
        free(deleteNode);
    }
}

int main(){
    Node* head = NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    traverse(head);
    deleteAlternateNode(head);
    traverse(head);


}
