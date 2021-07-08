//Singly Linked List

#include <bits/stdc++.h>
#define ln '\n'
#define sp ' '

using namespace std;

struct Node{
    int val;
    Node *next;
};

class SLL{
    public:
        Node *head;
        SLL(){
            head = NULL;
        }
        void ins(int val);//Insert value at end
        void del(int val);//Delete particular value from linked list
        void print();
        Node *rev();
};

void SLL::ins(int val){
    Node *p = head;
    if(!head){
        Node *temp = new Node;
        temp->val = val;
        temp->next = p;
        p = temp;
        head = p;
    }else{
        Node *temp = new Node;
        temp->val = val;
        p->next = temp;
        p = temp;
    }
}

void SLL::del(int val){
    Node *start = new Node;
    start->next = head;
    Node *p = start;
    if(!head){
        cout<<"List is Empty"<<ln;
        return;
    }
    while(p->next&&p->next->val!=val){
        p = p->next;
    }
    if(!p->next){
        cout<<"Value is not present in the list"<<ln;
    }else{
        Node *temp = p->next;
        p=temp->next;
        delete temp;
    }
    Node *temp = start->next;
    delete start;
    head = temp;
}

void SLL::print(){
    Node *p = head;
    if(!head){
        cout<<"List is Empty"<<ln;
        return;
    }
    cout<<"List is : ";
    while(p){
        cout<<p->val<<sp;
        p = p->next;
    }
    cout<<ln;
}

Node *SLL::rev(){
    if(!head||!head->next){
        return head;
    }
    Node *prev = NULL, *curr = head, *nex;
    while(curr){
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    return prev;
}


int main(){
    SLL l1;
    while(1){
        int choice;
        cout<<"1.   Insert"<<ln;
        cout<<"2.   Delete"<<ln;
        cout<<"3.   Print"<<ln;
        cout<<"4.   Reverse"<<ln;
        cout<<"5.   Exit"<<ln;
        cout<<"Enter your choice (1-5): ";
        cin>>choice;
        switch (choice)
        {
            case 1:
                int val;
                cout<<"Enter the value : ";
                cin>>val;
                l1.ins(val);
                break;
            case 2:
                cout<<"Enter the value : ";
                cin>>val;
                l1.del(val);
                break;
            case 3:
                l1.print();
                break;
            case 4:
                l1.head = l1.rev();
                break;
            case 5:
                exit(0);
            default:
                cout<<"Try Again..."<<ln;
                break;
        }
    }
    return 0;
}
