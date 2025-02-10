#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto& x : arr) cin>>x;
    sort(arr.begin(),arr.end());
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=+1;k<n;k++){
                if(arr[i] + arr[j]  == arr[k]){
                    cout<<i<<" "<<j<<" "<<k<<endl;
                    return;
                }
            }
        }
    }
    cout<<"NO Sequence Found."<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    solve();
	}

}
