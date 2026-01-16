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

int main(){

    node *p,*q,*r;
    p=new node();
    q=new node();
    r=new node();

    p->data = 10;
    q->data =20;
    r->data = 30;

    p->next = q;
    q->next = r;
    r->next = NULL;

    root = p;

    printing();
    searching(25);
    printFirst();
    printLast();
    printSecondLast();
    printRev(root);

    return 0;
}
