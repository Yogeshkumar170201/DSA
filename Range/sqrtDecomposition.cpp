//Square Root Decomposition
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <climits>

#define ln '\n'
#define sp ' '
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

void solve(){
    int n, q;
    cin>>n>>q;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int len = ceil(sqrt(n));
    vector<int>mini(len, INT_MAX);
    for(int i=0;i<n;i++){
        int ind = i/len;
        mini[ind] = min(mini[ind], arr[i]);
    }
    // vector<pair<int, int>>query(q);
    for(int i=0;i<q;i++){
        int l, r;
        cin>>l>>r;
        l--;
        r--;
        int j = l;
        int ans = INT_MAX;
        while(j<=r){
            if(j%len==0&&j+len-1<=r){
                ans = min(ans, mini[j/len]);
                j+=len;
            }else{
                ans = min(ans, arr[j]);
                j++;
            }
        }
        cout<<ans<<ln;
    }
}

int main(){
    FIO;
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}