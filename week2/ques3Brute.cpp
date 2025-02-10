#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n,key;
    cin>>n;
    vector<int> arr(n);
    for(auto& x : arr) cin>>x;
    sort(arr.begin(),arr.end());
    cin>>key;
    
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]-arr[i]==key)cnt++;
        }
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
