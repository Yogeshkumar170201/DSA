//Bridges in a Graph
//Tarjan's Algo
//O(V+E) --> Time Complexity

#include <bits/stdc++.h>
#define sp ' '
#define ln '\n'

using namespace std;

class Graph{
    private:
        list<int>*adj;
        int v;
        int timer;
        void Util(vector<int>&disc, vector<int>&low, int par, int u);
    public:
        set<pair<int, int>>s;
        Graph(){
            v = 0;
            adj = new list<int>[v];
            timer = 0;
        }
        Graph(int v){
            this->v = v;
            adj = new list<int>[this->v];
            timer = 0;
        }
        void addEdge(int u, int v);
        int isBridge(int c, int d);
};

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::Util(vector<int>&disc, vector<int>&low, int par, int u){
    disc[u] = timer;
    low[u] = timer;
    timer++;
    for(auto v: adj[u]){
        if(disc[v]==-1){
            Util(disc, low, u, v);
            low[u] = min(low[u], low[v]);
            if(low[v]>disc[u]){
                s.insert({u, v});
                s.insert({v, u});
            }
        }else if(par!=v){
            low[u] = min(low[u], disc[v]);
        }
    }
}
int Graph::isBridge(int c, int d) 
{
    vector<int>disc(v, -1);
    vector<int>low(v, -1);
    for(int i=0;i<v;i++){
        if(disc[i]==-1){
            Util(disc, low, -1, i);
        }
    }
    if(s.find({c,d})!=s.end()){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int V, E;
    cin>>V>>E;
    Graph g(V);
    for(int i=0;i<E;i++){
        int a, b;
        cin>>a>>b;
        g.addEdge(a, b);
        g.addEdge(b, a);
    }
    int c, d;
    cin>>c>>d;
    if(g.isBridge(c, d)){
        cout<<"YES"<<ln;
    }else{
        cout<<"NO"<<ln;
    }
    return 0;
}