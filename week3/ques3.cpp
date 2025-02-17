#include <bits/stdc++.h>
using namespace std;


bool hasDuplicate(vector<int>& arr){
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]==arr[i+1]) return 1;
    }
    return 0;
}

int main() {
	int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    sort(arr.begin(),arr.end());
    
    if(hasDuplicate(arr)){
        cout<<"YES"<<endl;
        
    }else{
        cout<<" NO"<<endl;
    }
    
    return 0;

}

