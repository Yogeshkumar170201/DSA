//Ternary Search
// O(2*log3(N)) --> Time Complexity

#include <bits/stdc++.h>

using namespace std;

void ternary(vector<int>&arr, int val, bool &f){
    int l = 0, r = arr.size()-1;
    while(l<=r){
        int m1 = l+(r-l)/3;
        int m2 = r-(r-l)/3;
        if(arr[m1]==val||arr[m2]==val){
            f = true;
            return;
        }else if(arr[m1]>val){
            r = m1-1;
        }else if(arr[m2]<val){
            l = m2+1;
        }else{
            l = m1+1;
            r = m2-1;
        }
    }
}

int main(){
    vector<int>arr = {1, 3, 6, 8, 10, 34};
    bool f = false;
    int val = 10;
    ternary(arr, val, f);
    if(f){
        cout<<"Found"<<"\n";
    }else{
        cout<<"Not Found"<<"\n";
    }
    return 0;
}