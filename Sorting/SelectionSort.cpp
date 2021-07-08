//SELECTION SORT
//O(N*N) --> Time Complexity
//O(1) --> Space Complexity
#include <bits/stdc++.h>

using namespace std;

void print(vector<int>&arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void selectionSort(vector<int>&arr){
    int n = arr.size();
    int mind;
    for(int i=0;i<n-1;i++){
        int mind = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mind]){
                mind = j;
            }
        }
        swap(arr[i], arr[mind]);
    }
}

int main(){
    vector<int>arr = {4, 1, 5, 3, 2, 9, 6};
    print(arr);
    selectionSort(arr);
    print(arr);
    return 0;
}
