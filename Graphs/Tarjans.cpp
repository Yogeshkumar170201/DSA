//Tarjan's Algo
//Strongly Connected components
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
        void SCCUtil(vector<vector<int>>&ans, vector<int>&disc, vector<int>&low, vector<bool>&ispre, stack<int>&s, int u);
    public:
        Graph(){
            v = 0;
            timer = 0;
            adj = new list<int>[v];
        }
        Graph(int v){
            this->v = v;
            timer = 0;
            adj = new list<int>[this->v];
        }
        void addEdge(int u, int v);
        vector<vector<int>> SCC();
        void print(vector<vector<int>>&ans);
};

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::SCCUtil(vector<vector<int>>&ans, vector<int>&disc, vector<int>&low, vector<bool>&ispre, stack<int>&s, int u){
    disc[u] = timer;
    low[u] = timer;
    timer++;
    s.push(u);
    ispre[u] = true;
    for(auto v:adj[u]){
        if(disc[v]==-1){
            SCCUtil(ans, disc, low, ispre, s, v);
            low[u] = min(low[u], low[v]);
        }else if(ispre[v]==true){
            low[u] = min(low[u], disc[v]);
        }
    }
    if(low[u]==disc[u]){
        vector<int>temp;
        int w = 0;
        while(!s.empty()&&s.top()!=u){
            w = s.top();
            ispre[w] = false;
            temp.push_back(w);
            s.pop();
        }
        if(!s.empty()){
            w = s.top();
            ispre[w] = false;
            temp.push_back(w);
            s.pop();
            ans.push_back(temp);
        }
    }
}

vector<vector<int>>Graph::SCC(){
    vector<vector<int>>ans;
    vector<int>disc(v, -1);
    vector<int>low(v, -1);
    vector<bool>ispre(v, false);
    stack<int>s;
    for(int i=0;i<v;i++){
        if(disc[i]==-1){
            SCCUtil(ans, disc, low, ispre, s, i);
        }
    }
    return ans;
}

void Graph::print(vector<vector<int>>&ans){
    for(int i=0;i<ans.size();i++){
        for(auto it: ans[i]){
            cout<<it<<sp;
        }
        cout<<ln;
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
    vector<vector<int>>ans = g.SCC();
    g.print(ans);
    return 0;
}

