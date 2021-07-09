#include <bits/stdc++.h>

using namespace std;

int vis;
vector<vector<int>>dp;
int tsp(int mask, int pos, vector<vector<int>>cost){
    if(mask==vis){
        return cost[pos][0];
    }
    if(dp[mask][pos]!=-1){
        return dp[mask][pos];
    }
    int ans = INT_MAX;
    for(int city=0;city<cost.size();city++){
        if(((1<<city)&mask)==0){
            int temp = cost[pos][city] + tsp(((1<<city)|mask), city, cost);
            ans = min(ans, temp);
        }
    }
    return dp[mask][pos] = ans;
}
int total_cost(vector<vector<int>>cost){
    int n = cost.size();
    vis = (1<<n)-1;
    dp.resize((1<<n), vector<int>(n, -1));
    return tsp(1, 0, cost);
}

int main(){
    vector<vector<int>>cost = {
                                {0,1000,5000},
                                {5000,0,1000},
                                {1000,5000,0}
                            };
    cout<<total_cost(cost);
    return 0;
}