#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n,key;
    cin>>n;
    vector<int> arr(n);
    for(auto& x : arr) cin>>x;
    sort(arr.begin(),arr.end());
    cin>>key;
    
    unordered_map<int,int> mpp;
    
    int cnt = 0;
    for(int i=0;i<n;i++){
        int val1 = arr[i] - key;
        int val2 = arr[i] + key;
        if(mpp.find(val1) != mpp.end()){
            cnt += mpp[val1];
        }
         if(mpp.find(val2) != mpp.end()){
            cnt += mpp[val2];
        }
        mpp[arr[i]]++;
    }
    cout<<cnt<<endl;

}

int main() {
	int t;
	cin>>t;
	while(t--){
	    solve();
	}

}
