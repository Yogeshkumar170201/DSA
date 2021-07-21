#include <bits/stdc++.h>
#define ln '\n'
#define sp ' '

using namespace std;

class Graph{
    private:
        vector<int>*adj;
        int v;
        vector<vector<int>>cap;
        int bfs(vector<int>&par, int s, int t);
    public:
        Graph(){
            v = 0;
            adj = new vector<int>[v];
            cap.resize(v, vector<int>(v, 0));
        }
        Graph(int size){
            v = size;
            adj = new vector<int>[v];
            cap.resize(v, vector<int>(v, 0));
        }
        void add_edge(int u, int v, int val);
        int max_flow(int s, int t);
};

void Graph::add_edge(int u, int v, int val){
    adj[u].push_back(v);
    cap[u][v] = val;
}

int Graph::bfs(vector<int>&par, int s, int t){
    fill(par.begin(), par.end(), -1);
    par[s] = -2;
    queue<pair<int, int>>q;
    q.push({s, INT_MAX});
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        int curr_ver = curr.first;
        int flow = curr.second;
        for(auto nex : adj[curr_ver]){
            if(par[nex]==-1&&cap[curr_ver][nex]){
                par[nex] = curr_ver;
                int new_flow = min(cap[curr_ver][nex], flow);
                if(nex==t){
                    return new_flow;
                }
                q.push({nex, new_flow});
            }
        }
    }
    return 0;
}

int Graph::max_flow(int s, int t){
    int flow = 0;
    vector<int>par(v);
    int new_flow;
    while(new_flow=bfs(par, s, t)){
        flow+=new_flow;
        int curr = t;
        while(curr!=s){
            int prev = par[curr];
            cap[prev][curr] -= new_flow;
            cap[curr][prev] += new_flow;
            curr=prev;
        }
    }
    return flow;
}

int main(){
    int v, e;
    cin>>v>>e;
    Graph g(v);
    for(int i=0;i<e;i++){
        int a, b, val;
        cin>>a>>b>>val;
        g.add_edge(a, b, val);
    }
    int s, t;
    cin>>s>>t;
    cout<<g.max_flow(s, t)<<ln;
    return 0;
}