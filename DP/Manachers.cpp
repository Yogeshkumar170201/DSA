//Longest Palindromic substring

#include <bits/stdc++.h>

using namespace std;

string longestPalindrome(string s) {
    int n = s.size();
    string x = "";
    x+='@';
    x+='#';
    for(int i=0;i<n;i++){
        x+=s[i];
        x+='#';
    }
    x+='&';
    int z = x.size();
    vector<int>dp(z, 0);
    int c = 0, r = 0;
    int ml = 0, mind = 0;
    for(int i=1;i<z-1;i++){
        int mir = c-(i-c);
        if(i<r){
            dp[i] = min(dp[mir], r-i);
        }
        while(x[i+dp[i]+1]==x[i-1-dp[i]]){
            dp[i]++;
        }
        if(i+dp[i]>r){
            c = i;
            r = i+dp[i];
        }
        if(dp[i]>ml){
            ml = dp[i];
            mind = i;
        }
    }
    int find = mind-ml+1;
    int ai = (find-2)/2;
    // cout<<ml<<ai;
    return s.substr(ai, ml);
}

int main(){
    string s = "abdbsba";
    cout<<longestPalindrome(s);
    return 0;
}