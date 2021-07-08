//GRAPH Implementation
//BFS
//DFS

#include <bits/stdc++.h>
#define sp ' '
#define ln '\n'

using namespace std;

class Graph{
    private:
        list<int>*adj;
        int v;
        void BFSUtil(int ind, vector<int>&vis, queue<int>&q);
        void DFSUtil(int ind, vector<int>&vis);
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
        void BFS();
        void DFS();
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

void Graph::BFSUtil(int ind, vector<int>&vis, queue<int>&q){
    q.push(ind);
    vis[ind] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout<<x<<sp;
        for(auto i = adj[x].begin();i!=adj[x].end();i++){
            if(!vis[*i]){
                q.push(*i);
                vis[*i] = 1;
            }
        }
    }
}

void Graph::BFS(){
    vector<int>vis(v, 0);
    queue<int>q;
    cout<<"BFS is : ";
    for(int i=0;i<v;i++){
        if(!vis[i]){
            BFSUtil(i, vis, q);
        }
    }
    cout<<ln;
}

void Graph::DFSUtil(int ind, vector<int>&vis){
    vis[ind] = true;
    cout<<ind<<sp;
    for(auto i = adj[ind].begin();i!=adj[ind].end();i++){
        if(!vis[*i]){
            DFSUtil(*i, vis);
        }
    }
}

void Graph::DFS(){
    vector<int>vis(v, 0);
    cout<<"DFS is : ";
    for(int i=0;i<v;i++){
        if(!vis[i]){
            DFSUtil(i, vis);
        }
    }
    cout<<ln;
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
    g1.BFS();
    g1.DFS();
    
    return 0;
}
