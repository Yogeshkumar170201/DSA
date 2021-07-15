//Union - Find
//Cycle in Undirected Graph --> O(V*E)

#include <bits/stdc++.h>
#define ln '\n'
#define sp ' '

using namespace std;

vector<int>dsfu;

int find(int v){
    if(dsfu[v]==-1){
        return v; 
    }
    return find(dsfu[v]);
}

void Union(int u, int v){
    int pu = find(u);
    int pv = find(v);
    dsfu[v] = u;
}

bool isCyclic(vector<pair<int, int>>edges){
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;
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
    int V = 4;
    int E = 4;
    vector<pair<int, int>>edges = {{0, 1}, {0, 3}, {2, 3}, {1, 2}};
    dsfu.resize(V, -1);
    if(isCyclic(edges)){
        cout<<"Cycle is Present"<<ln;
    }else{
        cout<<"Cycle is not Present"<<ln;
    }
    return 0;
}