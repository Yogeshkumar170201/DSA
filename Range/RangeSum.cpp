#include <bits/stdc++.h>
#define sp ' '
#define ln '\n'
#define int long long
const int mod=1000000007;
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

// void solve(){
//     int n, q;
//     cin>>n>>q;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     for(int i=1;i<n;i++){
//         arr[i] = min(arr[i-1], arr[i]);
//     }
//     for(int i=0;i<q;i++){
//         int a, b;
//         cin>>a>>b;
//         if(a==1){
//             cout<<arr[b-1]<<ln;
//         }else{
//             cout<<arr[b-1]-arr[a-2]<<ln;
//         }
//     }
// }

// void solve(){
//     int n, q;
//     cin>>n>>q;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     for(int i=0;i<q;i++){
//         int a, b, val;
//         cin>>a>>b>>val;
//         arr[a]+=val;
//         if(b!=n-1){
//             arr[b+1]-=val;
//         }
//     }
//     for(int i=1;i<n;i++){
//         arr[i] = arr[i]+arr[i-1];
//     }
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<sp;
//     }
//     cout<<ln;
// }

void solve(){
    int n, q, num;
    cin>>n>>q>>num;
    vector<int>cnt(n, 0);
    vector<pair<int, int>>query(q);
    for(int i=0;i<q;i++){
        int l, r;
        cin>>l>>r;
        query[i] = {l, r};
        cnt[l]+=1;
        if(r+1<n){
            cnt[r+1]-=1;
        }
    }
    for(int i=1;i<n;i++){
        cnt[i] = cnt[i-1]+cnt[i];
    }
    vector<int>val(n, 0);
    if(cnt[0]==num){
        val[0] = 1;
    }
    for(int i=1;i<n;i++){
        val[i] = val[i-1];
        if(cnt[i]==num){
            val[i]++;
        }
    }
    vector<int>val1(n, 0);
    if(cnt[0]==num+1){
        val1[0] = 1;
    }
    for(int i=1;i<n;i++){
        val1[i] = val1[i-1];
        if(cnt[i]==num+1){
            val1[i]++;
        }
    }
    int count = 0;
    for(int i=0;i<n;i++){
        if(cnt[i]==num){
            count++;
        }
    }
    int ans = 0;
    for(int i=0;i<q;i++){
        int l = query[i].first;
        int r = query[i].second;
        int loss = val[r];
        if(l>0){
            loss -= val[l-1];
        }
        int gain = val1[r];
        if(l>0){
            gain-=val1[l-1];
        }
        if(count-loss+gain>ans){
            ans = count-loss+gain;
        }
    }
    cout<<ans<<ln;
}

int32_t main(){
    FIO;
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}
