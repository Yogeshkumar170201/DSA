//Insertion Sort
//O(N) --> BEST CASE
//O(N*N) --> WORST CASE

//O(1) SPACE

#include <bits/stdc++.h>
using namespace std;

void print(vector<int>&arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void insertionSort(vector<int>&arr){
    int n = arr.size();
    for(int i=1;i<n;i++){
        int val = arr[i];
        int j = i-1;
        while(j>=0&&arr[j]>val){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = val;
    }
}

int main(){
    vector<int>arr = {5, 9, 2, 6, 3};
    print(arr);
    insertionSort(arr);
    print(arr);
    return 0;
}