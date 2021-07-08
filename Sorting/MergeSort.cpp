//MERGE SORT
//O(N*logN)  ---> Time Complexity
//O(N)  ---> Space Complexity

#include <bits/stdc++.h>

using namespace std;

void print(vector<int>&arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void merge(vector<int>&arr, int start, int mid, int end){
    int n1 = mid-start+1;
    int n2 = end-mid;
    vector<int>l(n1);
    vector<int>r(n2);
    for(int i=0;i<n1;i++){
        l[i] = arr[i+start];
    }
    for(int i=0;i<n2;i++){
        r[i] = arr[i+mid+1];
    }
    int k = start, i = 0, j = 0;
    while(i<n1&&j<n2){
        if(l[i]>=r[j]){
            arr[k++]=r[j++];
        }else{
            arr[k++]=l[i++];
        }
    }
    while(i<n1){
        arr[k++] = l[i++];
    }
    while(j<n2){
        arr[k++] = r[j++];
    }
}

void mergeSort(vector<int>&arr, int start, int end){
    if(start>=end){
        return;
    }
    int mid = start+(end-start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int main(){
    vector<int>arr = {3, 8, 1, 6, 4, 7, 3, 2};
    print(arr);
    int n = arr.size();
    mergeSort(arr, 0, n-1);
    print(arr);
    return 0;
}