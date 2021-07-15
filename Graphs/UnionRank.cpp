//Union by Rank and Path Compression
//Cycle Detection in an Undirected Graph

#include <bits/stdc++.h>
#define sp ' '
#define ln '\n'

using namespace std;

struct Node{
    int par;
    int rank;
};

vector<Node>dsfu;

int find(int v){
    if(dsfu[v].par==-1){
        return v;
    }
    return dsfu[v].par = find(dsfu[v].par);
}

void Union(int u, int v){
    int pu = find(u);
    int pv = find(v);
    if(pu!=pv){
        if(dsfu[pu].rank>dsfu[pv].rank){
            dsfu[pv].par = pu;
        }else if(dsfu[pu].rank>dsfu[pv].rank){
            dsfu[pu].par = pv;
        }else{
            dsfu[pu].par = pv;
            dsfu[pv].rank++;
        }
    }
}

bool isCyclic(vector<pair<int, int>>edges){
    for(auto i: edges){
        int u = i.first;
        int v = i.second;
        int pu = find(u);
        int pv = find(v);
        if(pu==pv){
            return true;
        }
        Union(pu, pv);
    }
    return false;
}

int main(){
    int V = 5;
    int E = 5;
    vector<pair<int, int>>edges = {{0, 1}, {2, 3}, {1, 2}, {0, 4}, {4, 3}};
    dsfu.resize(V);
    for(int i=0;i<V;i++){
        dsfu[i].par = -1;
        dsfu[i].rank = 0;
    }
    if(isCyclic(edges)){
        cout<<"Cycle is Present"<<ln;
    }else{
        cout<<"No Cycle"<<ln;
    }
    return 0;
}