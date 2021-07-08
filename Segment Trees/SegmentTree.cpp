//Segment Tree
#include <bits/stdc++.h>

using namespace std;

void buildTree(vector<int>&arr, vector<int>&tree, int ind, int s, int e){
    if(s>e){
        return ;
    }
    if(s==e){
        tree[ind] = arr[s];
        return;
    }
    int mid = s+(e-s)/2;
    buildTree(arr, tree, 2*ind, s, mid);
    buildTree(arr, tree, 2*ind+1, mid+1, e);
    int left = tree[2*ind];
    int right = tree[2*ind+1];
    tree[ind] = min(tree[2*ind], tree[2*ind+1]);
}

int query(vector<int>&tree, int ind, int s, int e, int qs, int qe){
    if(qs>e||qe<s){
        return INT_MAX;
    }
    if(s>=qs&&e<=qe){
        return tree[ind];
    }
    int mid = s+(e-s)/2;
    int lans = query(tree, 2*ind, s, mid, qs, qe);
    int rans = query(tree, 2*ind+1, mid+1, e, qs, qe);
    return min(lans, rans);
}

void updateNode(vector<int>&tree, int ind, int s, int e, int i, int val){
    if(i<s&&i>e){
        return;
    }
    if(s==e){
        tree[ind] = val;
    }
    int mid = s+(e-s)/2;
    updateNode(tree, 2*ind, s, mid, i, val);
    updateNode(tree, 2*ind+1, mid+1, e, i, val);
    tree[ind] = min(tree[2*ind], tree[2*ind+1]);
}

void UpdateRange(vector<int>&tree, int ind, int s, int e, int rs, int re, int inc){
    if(rs>e||s>re){
        return;
    }
    if(s==e){
        tree[ind] +=inc;
    }
    int mid = s+(e-s)/2;
    UpdateRange(tree, 2*ind, s, mid, rs, re, inc);
    UpdateRange(tree, 2*ind+1, mid+1, e, rs, re, inc);
    tree[ind] = min(tree[2*ind], tree[2*ind+1]);
}

int main(){
    vector<int>arr = {-3, 9, 0, 4, -2, 8, 6};
    int n = arr.size();
    vector<int>tree(4*n+1);
    buildTree(arr, tree, 1, 0, n-1);
    cout<<query(tree, 1, 0, n-1, 1, 4)<<"\n";
    cout<<query(tree, 1, 0, n-1, 0, 4)<<"\n";
    cout<<query(tree, 1, 0, n-1, 1, 3)<<"\n";
    return 0;
}
