#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, key;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>key;
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        if(mpp.find(key-arr[i]) != mpp.end()){
            cout<<key-arr[i] <<" "<<arr[i]<<endl;
            return;
        }
        mpp[arr[i]]++;
    }
    cout<<"No such element exist"<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    solve();
	}

}
