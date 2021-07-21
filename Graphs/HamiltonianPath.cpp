#include <bits/stdc++.h>
#define ln '\n'
#define sp ' '

using namespace std;

class Graph{
    private:
        list<int>*adj;
        int v;
        bool dfs(vector<bool>&vis, int i, int cnt);
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
        bool check();
};

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

bool Graph::dfs(vector<bool>&vis, int i, int cnt){
    if(cnt==v){
        return true;
    }
    vis[i] = true;
    for(auto v: adj[i]){
        if(!vis[v]){
            if(dfs(vis, v, cnt+1)){
                return true;
            }
        }
    }
    vis[i] = false;
    return false;
}

bool Graph::check()
{
    for(int i=1;i<=v;i++){
        int cnt = 1;
        vector<bool>vis(v, false);
        if(dfs(vis, i, cnt)){
            return true;
        }    
    }
    return false;
}

int main(){
    int V, E;
    cin>>V>>E;
    Graph g(V);
    for(int i=0;i<E;i++){
        int a, b;
        cin>>a>>b;
        g.addEdge(a-1, b-1);
        g.addEdge(b-1, a-1);
    }
    if(g.check()){
        cout<<"Hamiltonian Path Exist"<<ln;
    }else{
        cout<<"Hamiltonian Path does not exist"<<ln;
    }
    return 0;
}