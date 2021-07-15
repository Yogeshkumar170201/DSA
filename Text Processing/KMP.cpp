//Knuth Morris Pratt
// O(m+n) --> Time Complexity

//Length of longest common preffix and suffix
// O(n) --> Time Complexity


#include <bits/stdc++.h>
#define ln '\n'
#define sp ' '

using namespace std;

int lps(string s){
    if(s.size()==0){
        return 0;
    }
    int i = 0, j = 1;
    int n = s.size();
    vector<int>dp(n);
    dp[0] = 0;
    while(j<n){
        if(s[i]==s[j]){
            dp[j] = i+1;
            i++;
            j++;
        }else{
            if(i==0){
                dp[j] = 0;
                j++;
            }else{
                i = dp[i-1];
            }
        }
    }
    return dp[n-1];
}

int kmp(string txt, string pat){
    string temp = pat+"$"+txt;
    int n = temp.size();
    int cnt = 0;
    int i = 0, j = 1;
    vector<int>dp(n);
    dp[0] = 0;
    while(j<n){
        if(temp[i]==temp[j]){
            dp[j] = i+1;
            i++;
            j++;
        }else{
            if(i==0){
                dp[j] = 0;
                j++;
            }else{
                i = dp[i-1];
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dp[i]==pat.size()){
            cnt++;
        }
    }
    return cnt;
}


int main(){
    string txt = "aabaacaacaab";
    string pat = "aab";
    int si = lps(txt);
    cout<<txt.substr(0, si)<<ln;;
    cout<<kmp(txt, pat)<<ln;
    return 0;
}