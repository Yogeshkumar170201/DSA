//Iterative DFS
//Topological Sorting

#include <bits/stdc++.h>
#define sp ' '
#define ln '\n'

using namespace std;

class Graph{
    private:
        list<int>*adj;
        int v;
        void topoUtil(int u, stack<int>&s, vector<bool>&vis);
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
        void DFS();
        void topologicalSort();
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

void Graph::DFS(){
    vector<bool>vis(v, false);
    stack<int>s;
    s.push(0);
    while(!s.empty()){
        int x = s.top();
        s.pop();
        if(!vis[x]){
            cout<<x<<sp;
            vis[x] = true;
        }
        for(auto i: adj[x]){
            if(!vis[i]){
                s.push(i);
            }
        }
    }
}

void Graph::topoUtil(int u, stack<int>&s, vector<bool>&vis){
    vis[u] = true;
    for(auto i : adj[u]){
        if(!vis[i]){
            topoUtil(i, s, vis);
        }
    }
    s.push(u);
}

void Graph::topologicalSort(){
    vector<bool>vis(v, false);
    stack<int>s;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            topoUtil(i, s, vis);
        }
    }
    while(!s.empty()){
        cout<<s.top()<<sp;
        s.pop();
    }
    cout<<ln;
}

int main(){
    // Graph g1(9);

    // g1.addEdge(0, 1);
    // g1.addEdge(0, 3);
    // g1.addEdge(0, 4);
    // g1.addEdge(1, 2);
    // g1.addEdge(1, 4);
    // g1.addEdge(2, 5);
    // g1.addEdge(3, 4);
    // g1.addEdge(3, 6);
    // g1.addEdge(4, 5);
    // g1.addEdge(4, 7);
    // g1.addEdge(6, 4);
    // g1.addEdge(6, 7);
    // g1.addEdge(7, 5);
    // g1.addEdge(7, 8);

    // //g1.print();
    // g1.DFS();
    // cout<<ln;
    // g1.topologicalSort();
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.topologicalSort();
    return 0;
}
