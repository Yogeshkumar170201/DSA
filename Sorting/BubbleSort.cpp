//BUBBLE SORT
//O(n) --> Best Time Complexity
//O(N*N) --> Worst Time Complexity
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

void bubbleSort(vector<int>&arr){
    int n = arr.size();
    bool swapped = false;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

int main(){
    vector<int>arr = {4, 1, 5, 3, 2, 9, 6};
    print(arr);
    bubbleSort(arr);
    print(arr);
    return 0;
}
