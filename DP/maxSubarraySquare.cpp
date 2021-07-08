//Maximum sum of subarray after replacing one element with its square

#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>&arr){
    int n = arr.size();
    vector<vector<int>>dp(n, vector<int>(2, 0));
    dp[0][0] = arr[0];
    dp[0][1] = arr[0]*arr[0];
    int max_sum = max(dp[0][0], dp[0][1]);
    for(int i=1;i<n;i++){
        //Maximum of Current Element and curr + prev_max without square
        dp[i][0] = max(dp[i-1][0]+arr[i], arr[i]);
        //Max of square of curr and prev_max without sq + curr_sq
        dp[i][1] = max(dp[i-1][0]+(arr[i]*arr[i]), arr[i]*arr[i]);
        //Max of prev_sq + curr and curr_sq
        dp[i][1] = max(dp[i][1], dp[i-1][1]+arr[i]);
        //take max of cuur_max, curr_sq, curr
        max_sum = max(max_sum, dp[i][0]);
        max_sum = max(max_sum, dp[i][1]);
    }
    return max_sum;
}

int main(){
    vector<int>arr = {1, -5, 8, 12, -8};
    cout<<solve(arr);
    return 0;
}