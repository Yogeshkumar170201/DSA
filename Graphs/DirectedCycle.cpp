//Cycle in Directed Graph

#include <bits/stdc++.h>
#define sp ' '
#define ln '\n'

using namespace std;

class Graph{
    private:
        list<int>*adj;
        int v;
        bool isCyclicUtil(int ind, vector<bool>&vis, vector<bool>&rec);
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

bool Graph::isCyclic(){
    vector<bool>rec(v, false);
    vector<bool>vis(v, false);
    for(int i=0;i<v;i++){
        if(!vis[i]&&isCyclicUtil(i, vis, rec)){
            return true;
        }
    }
    return false;
}

bool Graph::isCyclicUtil(int ind, vector<bool>&vis, vector<bool>&rec){
    if(!vis[ind]){
        rec[ind] = true;
        vis[ind] = true;
        for(auto i=adj[ind].begin();i!=adj[ind].end();i++){
            if(!vis[*i]&&isCyclicUtil(*i, vis, rec)){
                return true;
            }else if(rec[*i]){
                return true;
            }
        }
    }
    rec[ind] = false;
    return false;
}

int main(){
    Graph g1(9);

    g1.addEdge(0, 1);
    g1.addEdge(0, 3);
    g1.addEdge(0, 4);
    g1.addEdge(1, 2);
    g1.addEdge(1, 4);
    g1.addEdge(2, 5);
    g1.addEdge(3, 4);
    g1.addEdge(3, 6);
    g1.addEdge(4, 5);
    g1.addEdge(4, 7);
    g1.addEdge(6, 4);
    g1.addEdge(6, 7);
    g1.addEdge(7, 5);
    g1.addEdge(7, 8);

    g1.print();

    if(g1.isCyclic()){
        cout<<"Graph contains Cycle"<<ln;
    }else{
        cout<<"Graph does not contain any Cycle"<<ln;
    }

    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.addEdge(3, 0);

    g2.print();

    if(g2.isCyclic()){
        cout<<"Graph contains Cycle"<<ln;
    }else{
        cout<<"Graph does not contain any Cycle"<<ln;
    }

    return 0;
}
