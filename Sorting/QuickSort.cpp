//Quick Sort
//O(NlogN) --->  BEST and AVERAGE Case
//O(N*N) ----> WORST CASE
//O(1) -----> SPACE

#include <bits/stdc++.h>

using namespace std;

void print(vector<int>&arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int partition(vector<int>&arr, int start, int end){
    int pind = start;
    int piv = arr[end];
    for(int i=start;i<end;i++){
        if(arr[i]<=piv){
            swap(arr[i], arr[pind]);
            pind++;
        }
    }
    swap(arr[end], arr[pind]);
    return pind;
}

void quickSort(vector<int>&arr, int start, int end){
    if(start>=end){
        return;
    }
    int pind = partition(arr, start, end);
    quickSort(arr, start, pind-1);
    quickSort(arr, pind+1, end);
}

int main(){
    vector<int>arr = {5, 2, 6, 4, 3, 1};
    int n = arr.size();
    print(arr);
    quickSort(arr, 0, n-1);
    print(arr);
    return 0;
}
