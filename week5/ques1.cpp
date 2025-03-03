#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<char> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>fq(26,0);
    for(int i=0;i<n;i++){
        fq[arr[i]-'a']++;
    }
    int maxf = 1;
    char maxc ='.';
    for(int i=0;i<n;i++){
        if(fq[i]>maxf){
            maxf = fq[i];
            maxc = 'a'+i;
        }
    }
    if(maxf==1){
        cout<<"No duplicate elements"<<endl;
    }else{
        cout<<maxc<<" - "<<maxf<<endl;
    }
    
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    solve();
	}

}
