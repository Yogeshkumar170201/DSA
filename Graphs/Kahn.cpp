//Kahn's Algorithm for finding topological Sort

#include <bits/stdc++.h>
#define sp ' '
#define ln '\n'

using namespace std;

class Graph{
    private:
        list<int>*adj;
        int v;
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
        void topoSort();
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

void Graph::topoSort(){
    //Stores Indegree
    vector<int>indeg(v, 0);
    for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            indeg[it]++;
        }
    }
    //Push vertex having zero indegree in queue
    queue<int>q;
    for(int i=0;i<v;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    int cnt = 0;
    vector<int>ans;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for(auto it:adj[x]){
            if(--indeg[it]==0){
                q.push(it);
            }
        }
        cnt++;
    }
    if(cnt!=v){
        cout<<"Graph contains cycle"<<ln;
        return;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<sp;
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

    // g1.print();
    // g1.topoSort();
    Graph g2(6);
    g2.addEdge(5, 2);
    g2.addEdge(5, 0);
    g2.addEdge(4, 0);
    g2.addEdge(4, 1);
    g2.addEdge(2, 3);
    g2.addEdge(3, 1);

    g2.topoSort();
    cout<<ln;

    Graph g(5);
    g.addEdge(4, 4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.topoSort();
    return 0;
}
