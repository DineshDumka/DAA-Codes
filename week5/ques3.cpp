#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    vector<int>b(m);
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    
    vector<int>ans;
    int  i = 0 , j = 0;
    while(i<n && j<m){
        if(a[i]<b[j]) i++;
        else if(b[j]<a[i]) j++;
        else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    if(ans.size()){
        for(auto x : ans){
            cout<<x<<" ";
        }
        cout<<endl;
    }else{
        cout<<"No common element"<<endl;
    }
}

int main() {
	int t=1;
	//cin>>t;
	while(t--){
	    solve();
	}

}
