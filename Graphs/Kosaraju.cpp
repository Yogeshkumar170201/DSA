//Strongly Connected Componenets in DAG

#include <bits/stdc++.h>
#define sp ' '
#define ln '\n'

using namespace std;


class Graph{
    private:
        list<int>*adj;
        int v;
        void dfs(int u, vector<bool>&vis, stack<int>&s);
        void dfs1(vector<int>g[],int u, vector<bool>&vis);
    public:
        Graph(){
            v = 0;
            adj = new list<int>[v];
        }
        Graph(int v){
            this->v = v;
            adj = new list<int>[this->v];
        }
        void addEdge(int u, int v);
        void print();
        int kosaraju();
};

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::print(){
    for(int i=0;i<v;i++){
        cout<<i<<sp<<"->"<<sp;
        for(auto x:adj[i]){
            cout<<x<<sp;
        }
        cout<<ln;
    }
}

void Graph::dfs(int u, vector<bool>&vis, stack<int>&s){
    vis[u] = true;
    for(auto it:adj[u]){
        if(!vis[it]){
            dfs(it, vis, s);
        }
    }
    s.push(u);
}

void Graph::dfs1(vector<int>g[], int u, vector<bool>&vis){
    vis[u] = true;
    for(auto it:g[u]){
        if(!vis[it]){
            dfs1(g, it, vis);
        }
    }
}

int Graph::kosaraju()
{
    vector<bool>vis(v, false);
    stack<int>s;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i, vis, s);
        }
    }
    
    vector<int>g[v];
    for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            g[it].push_back(i);
        }
    }
    // fill(vis.begin(), vis.end(), false);
    for(int i=0;i<v;i++){
        vis[i] = false;
    }
    // memset(vis, false, sizeof(vis));
    int cnt = 0;
    while(!s.empty()){
        int x = s.top();
        s.pop();
        if(!vis[x]){
            dfs1(g, x, vis);
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int V = 6;
    Graph g(V);
    g.addEdge(5, 5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    cout<<g.kosaraju();
    return 0;
}