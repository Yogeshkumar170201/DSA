#include <bits/stdc++.h>

using namespace std;

vector<int>tin, tout;
int timer;

void dfs(int u, int p, vector<vector<int>>&lookup, int si, vector<vector<int>>&g){
    tin[u] = ++timer;
    lookup[u][0] = p;
    for(int i=1;i<si;i++){
        lookup[u][i] = lookup[lookup[u][i-1]][i-1];
    }
    for(auto v:g[u]){
        if(v!=p){
            dfs(v, u, lookup, si, g);
        }
    }
    tout[u]=++timer;
}

bool is_ancestor(int u, int v){
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}

int lca(int u, int v, int si, vector<vector<int>>&lookup){
    
    if(is_ancestor(u, v)){
        return u;
    }
    
    if(is_ancestor(v, u)){
        return v;
    }
    
    for(int i=si-1;i>=0;i--){
        if(!is_ancestor(u, v)){
            u = lookup[u][i];
        }
    }
    return lookup[u][0];
}

int main() {
    int n = 7;
    vector<vector<int>>edges = {{1,2},{1,3},{1,4},{2,5},{2,6},{4,7}};
    vector<vector<int>>queries = {{3,7}, {6,4}, {6,2}};
    vector<vector<int>>g(n+1);
    for(auto i:edges){
        g[i[0]].push_back(i[1]);
        g[i[1]].push_back(i[0]);
    }
    tin.resize(n+1, 0);
    tout.resize(n+1, 0);
    timer = 0;
    int si = floor(log2(n))+1;
    vector<vector<int>>lookup(n+1, vector<int>(si, -1));
    dfs(1, 1, lookup, si, g);
    
    for(auto i:queries){
        int u = i[0];
        int v = i[1];
        cout<<lca(u, v, si, lookup)<<endl;
    }
    return 0;
}
