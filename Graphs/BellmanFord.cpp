//Bellman Ford
//Single Souce Shortest Path
//O(V*E) --> Time Complexity
//O(V) --> Space Complexity

#include <bits/stdc++.h>
#define ln '\n'
#define sp ' '

using namespace std;

vector<int> bellmanFord(vector<vector<int>>&graph, int src){
    int V = graph.size();
    vector<int>dist(V, INT_MAX);
    vector<pair<int, int>>edge;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(graph[i][j]){
                edge.push_back({i, j});
            }
        }
    }
    dist[src] = 0;
    for(int i=0;i<V-1;i++){
        for(int j=0;j<edge.size();j++){
            int u = edge[j].first;
            int v = edge[j].second;
            if(graph[u][v]){
                if(dist[v]>graph[u][v]+dist[u]){
                    dist[v] = dist[u]+graph[u][v];
                }
            }
        }
    }
    bool flag = false;
    for(int j=0;j<edge.size();j++){
        int u = edge[j].first;
        int v = edge[j].second;
        if(graph[u][v]){
            if(dist[v]>graph[u][v]+dist[u]){
                flag = true;
                dist[v] = dist[u]+graph[u][v];
            }
        }
    }
    if(flag){
        cout<<"Negative Cycle is Present"<<ln;
        return {};
    }else{
        return dist;
    }
}

int main(){
    int V = 9;
    vector<vector<int>>graph = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                                { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                                { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                                { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                                { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                                { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                                { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                                { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                                { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    int src = 0;
    vector<int>ans = bellmanFord(graph, src);
    for(int i=0;i<V;i++){
        cout<<ans[i]<<sp;
    }
    cout<<ln;
    return 0;
    return 0;
}