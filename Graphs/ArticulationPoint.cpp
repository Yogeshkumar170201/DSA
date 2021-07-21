#include <bits/stdc++.h>
#define ln '\n'
#define sp ' '

using namespace std;

class Graph{
    private:
        list<int>*adj;
        int v;
        void tarjanUtil(vector<bool>&isPre, vector<int>&disc, vector<int>&low, int u, int par);
        int timer;
    public:
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
        vector<int> tarjan();
};

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::tarjanUtil(vector<bool>&ap, vector<int>&disc, vector<int>&low, int u, int par){
    disc[u] = timer;
    low[u] = timer;
    int children = 0;
    timer++;
    for(auto v : adj[u]){
        if(disc[v]==-1){
            children++;
            tarjanUtil(ap, disc, low, v, u);
            low[u] = min(low[u], low[v]);
            if(low[v]>=disc[u]&&par!=-1){
                ap[u] = true;
            }
            if(par==-1&&children>1){
                ap[u] = true;
            }
        }else{
            low[u] = min(low[u], disc[v]);
        }
    }
}

vector<int> Graph::tarjan(){
    vector<bool>ap(v, false);
    vector<int>disc(v, -1);
    vector<int>low(v, -1);
    for(int i=0;i<v;i++){
        if(disc[i]==-1){
            tarjanUtil(ap, disc, low, i, -1);
        }
    }
    vector<int>ans;
    for(int i=0;i<v;i++){
        if(ap[i]){
            ans.push_back(i);
        }
    }
    return ans;
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
    vector<int>ans = g.tarjan();
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<sp;
    }
    cout<<ln;
    return 0;
}