//Cycle in Undirected Graph

#include <bits/stdc++.h>
#define sp ' '
#define ln '\n'

using namespace std;

class Graph{
    private:
        list<int>*adj;
        int v;
        bool isCyclicUtil(int ind, vector<bool>&vis, int par);
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
        bool isCyclic();
};

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
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

bool Graph::isCyclicUtil(int ind, vector<bool>&vis, int par){
    vis[ind] = true;
    for(auto i = adj[ind].begin();i!=adj[ind].end();i++){
        if(!vis[*i]){
            if(isCyclicUtil(*i, vis, ind)){
                return true;
            }
        }else if(*i!=par){
            return true;
        }
    }
    return false;
}

bool Graph::isCyclic(){
    vector<bool>vis(v);
    for(int i=0;i<v;i++){
        vis[i] = false;
    }
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(isCyclicUtil(i, vis, -1)){
                return true;
            }
        }
    }
    return false;
}


int main(){
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.print();
    if(g1.isCyclic()){
        cout<<"Graph contains Cycle"<<ln;
    }else{
        cout<<"Graph does not contain any Cycle"<<ln;
    }

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.print();
    if(g2.isCyclic()){
        cout<<"Graph contains Cycle"<<ln;
    }else{
        cout<<"Graph does not contain any Cycle"<<ln;
    }

    return 0;
}
