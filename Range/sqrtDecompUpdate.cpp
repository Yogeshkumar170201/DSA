#include <bits/stdc++.h>
#define sp ' '
#define ln '\n'
#define int long long
const int mod=1000000007;
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

void solve(){
    int n, q;
    cin>>n>>q;
    int  x[n];
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    int len = ceil(sqrt(n));
    vector<int>sum(len, 0);
    for(int i=0;i<n;i++){
        int ind = i/len;
        sum[ind]+=x[i];
    }
    for(int i=0;i<q;i++){
        int t, l, r;
        cin>>t>>l>>r;
        int ans = 0;
        if(t==1){
            l--;
            int pos = x[l];
            x[l] = r;
            int ind = l/len;
            sum[ind]-=pos;
            sum[ind]+=r;
        }else if(t==2){
            l--;
            r--;
            int j = l;
            while(j<=r){
                if(j%len==0&&j+len-1<=r){
                    ans+=sum[j/len];
                    j+=len;
                }else{
                    ans+=x[j];
                    j++;
                }
            }
            cout<<ans<<ln;
        }
    }
}


int32_t main(){
    FIO;
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}
