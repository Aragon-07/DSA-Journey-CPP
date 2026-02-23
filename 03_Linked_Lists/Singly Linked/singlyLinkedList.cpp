#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
};

node *root=NULL;

void printing(){
    node* curr=root;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

void searching(int val){
    node* curr=root;
    int flag=0;
    while(curr!=NULL){
        if(curr->data==val){
            cout<<"Found"<<endl;
            flag=1;
            break;
        }
        curr=curr->next;
    }
    if(flag==0){
        cout<<"Not found"<<endl;
    }
}

void printFirst(){
    cout<<root->data<<endl;
}

void printLast(){
    node *curr=root;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    cout<<curr->data<<endl;
}

void printSecondLast(){
    node *curr=root;
    node *prev=root;
    while(curr->next!=NULL){
        prev=curr;
        curr=curr->next;
    }
    cout<<prev->data<<endl;
}

void printRev(node *temp){
    if(temp!=NULL){
        printRev(temp->next);
        cout<<temp->data<<" ";
    }
}

void insertFirst(int val){
    node *temp;
    temp=new node();

    temp->data=val;
    temp->next=root;
    root = temp;
}

void insertLast(int val){
    node *temp;
    temp = new node();
    temp ->data = val;
    temp ->next =NULL;
    node *curr=root;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
}

int main(){

    insertFirst(10);
    insertFirst(20);
    insertFirst(30);
    printing();

    return 0;
}

