//Dijkstra Algorithm
//Single Source to Multiple Destination
//O(V*V) --> Time Complexity
//O(V) --> Space Complexity

#include <bits/stdc++.h>
#define ln '\n'
#define sp ' '

using namespace std;

int minVer(vector<int>&dist, vector<bool>&vis){
    int ind = -1;
    int dis = INT_MAX;
    for(int i=0;i<dist.size();i++){
        if(dist[i]<dis&&!vis[i]){
            dis = dist[i];
            ind = i;
        }
    }
    return ind;
}

vector<int> dijkstra(vector<vector<int>>&graph, int src){
    int V = graph.size();
    vector<int>dist(V, INT_MAX);
    vector<bool>vis(V, false);
    dist[src] = 0;
    for(int i=0;i<V;i++){
        int u = minVer(dist, vis);
        vis[u] = true;
        for(int v=0;v<V;v++){
            if(graph[u][v]){
                if(dist[v]>dist[u]+graph[u][v]){
                    dist[v] = dist[u]+graph[u][v];
                }
            }
        }
    }
    return dist;
}

int main(){
    int V = 9;
    vector<vector<int>>graph(V, vector<int>(V));
    graph =     { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    int src = 0;
    vector<int>ans = dijkstra(graph, src);
    for(int i=0;i<V;i++){
        cout<<ans[i]<<sp;
    }
    cout<<ln;
    return 0;
}