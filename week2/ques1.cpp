#include <bits/stdc++.h>
using namespace std;

int LowerBound(vector<int>&arr, int key){
    int n = arr.size();
    int low = 0, high = n-1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid] >= key){
            high = mid - 1;
        }else low = mid +1;
    }
    return low;
}

int UpperBound(vector<int>&arr, int key){
    int n = arr.size();
    int low = 0, high = n-1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid] > key){
            high = mid - 1;
        }else low = mid +1;
    }
    return low;
}

void solve(){
    int n, key;
    cin>>n;
    vector<int> arr(n);
    for(auto& x : arr) cin>>x;
    sort(arr.begin(),arr.end());
    cin>>key;
    
    
    int ub = UpperBound(arr,key);
    int lb =  LowerBound(arr,key);
    
    cout<<"key : "<<key << " -- "<< "cnt : "<< ub-lb<<endl;
    
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    solve();
	}

}
