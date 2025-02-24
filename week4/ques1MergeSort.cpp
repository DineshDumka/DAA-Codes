#include <bits/stdc++.h>
using namespace std;

int comparison = 0;
int inversion = 0;

void merge(vector<int>& arr, int start, int mid,  int end){
    vector<int>v;
    int i = start, j = mid+1;
    while(i<=mid && j<=end){
        comparison++;
        if(arr[i]<=arr[j]) {
            v.push_back(arr[i]);
            i++;
        }
        else {
            inversion += (mid - i + 1);
            v.push_back(arr[j]);
            j++;
        }
        
    }
    if(i<=mid){
         while(i<=mid){
            v.push_back(arr[i]);
            i++;
        }
    }
    if(j<=end){
         while(j<=end){
            v.push_back(arr[j]);
            j++;
        }
    }
    int ind = 0;
    for(int k=start;k<=end;k++){
        arr[k] = v[ind++];
    }
}

void mergeSort(vector<int>& arr, int start, int end){
    if(start==end) return;
    int mid = (start+end)/2;
    mergeSort(arr,start, mid);
    mergeSort(arr,mid+1,end)                                                             ;
    merge(arr,start,mid, end);
}

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    comparison = 0;
    inversion = 0;
    
    mergeSort(arr,0,n-1);
    
    // display
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"inversions : "<<inversion<<endl;
    cout<<"comparisons : "<< comparison<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
	
}
