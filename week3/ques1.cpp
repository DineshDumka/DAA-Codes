#include <bits/stdc++.h>
using namespace std;

void display(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        
        cout<<arr[i]<<" ";
        
    }
    cout<<endl;
}


void insertionSort(vector<int>& arr){
    int n = arr.size();
    int comparisons = 0;
    int shifts = 0;
    for(int i=1;i<n;i++){
        int key = arr[i];
        
        int j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
            comparisons++;
            shifts++;
        }
        arr[j+1] = key;
        comparisons++;
    }
   
    cout<<"comparisons : " <<comparisons<<endl;
     cout<<"Shifts : " <<shifts<<endl;
}



int main() {
	int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    //display(arr);
    
    insertionSort(arr);

    
    display(arr);

}
