#include <bits/stdc++.h>
using namespace std;

void display(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        
        cout<<arr[i]<<" ";
        
    }
    cout<<endl;
}


void selectionSort(vector<int>& arr){
    int n = arr.size();
    int comparisons = 0;
    int swaps = 0;
    for(int i=0;i<n-1;i++){
        int mini = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mini]){
                mini = j;
            }
            comparisons++;
        }
        
        if(mini != i){
            swap(arr[mini], arr[i]);
            swaps++;
        }
        //comparisons++;
    }
    
    cout<<"comparisons : " <<comparisons<<endl;
     cout<<"swaps : " <<swaps<<endl;
}



int main() {
	int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    //display(arr);
    
    selectionSort(arr);

    
    display(arr);

}
