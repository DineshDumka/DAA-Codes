#include <bits/stdc++.h>
using namespace std;

void linearSearch(vector<int> &arr, int n, int key) {
    int comparisons = 0;
    bool found = false;
    
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == key) {
            found = true;
            break;
        }
    }
    
    if (found)
        cout << "Present " << comparisons << endl;
    else
        cout << "Not Present " << comparisons << endl;
}

int main() {
    int t;
    cin >> t;  
    
    while (t--) {
        int n;
        cin >> n;  
        vector<int>arr(n);
        
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        int key;
        cin >> key; 
        
        linearSearch(arr, n, key);
    }
    
    return 0;
}
