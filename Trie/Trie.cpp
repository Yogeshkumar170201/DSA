#include <bits/stdc++.h>

using namespace std;

struct Node{
    Node *childs[26];
    bool isEnd;
};

Node *root;

Node *getNode(){
    Node *p = new Node;
    p->isEnd = false;
    for(int i=0;i<26;i++){
        p->childs[i] = NULL;
    }
    return p;
}

void ins(string word){
    Node *curr = root;
    for(int i=0;i<word.length();i++){
        char ch = word[i];
        if(curr->childs[ch-'a']==NULL){
            curr->childs[ch-'a'] = getNode();
        }
        curr = curr->childs[ch-'a'];
    }
    curr->isEnd = true;
}

bool srch(string word){
    Node *curr = root;
    for(int i=0;i<word.length();i++){
        char ch = word[i];
        if(curr->childs[ch-'a']==NULL){
            return false;
        }
        curr = curr->childs[ch-'a'];
    }
    return curr->isEnd;
}

bool startsWith(string prefix){
    Node *curr = root;
    for(int i=0;i<prefix.length();i++){
        char ch = prefix[i];
        if(curr->childs[ch-'a']==NULL){
            return false;
        }
        curr = curr->childs[ch-'a'];
    }
    return true;
}

int main(){
    root = new Node;
    ins("apple");
    cout<<srch("apple")<<"\n";
    ins("app");
    cout<<startsWith("app")<<"\n";
    cout<<srch("apples")<<"\n";
    return 0;
}
