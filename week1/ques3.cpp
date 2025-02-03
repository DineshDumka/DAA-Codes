#include <iostream>
#include <cmath>
using namespace std;

int jumpSearch(int arr[], int n, int key, int &comparisons) {
    int step = sqrt(n); 
    int prev = 0;

    
    while (arr[min(step, n) - 1] < key) {
        comparisons++;
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1; 
    }

    
    while (arr[prev] < key) {
        comparisons++;
        prev++;
        if (prev == min(step, n))
            return -1; 
    }

    comparisons++;
    if (arr[prev] == key)
        return prev;
    return -1;
}

void searchInSortedArray(int arr[], int n, int key) {
    int comparisons = 0;
    int result = jumpSearch(arr, n, key, comparisons);
    if (result != -1)
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
        int arr[n];
        
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        int key;
        cin >> key; 
        
        searchInSortedArray(arr, n, key);
    }
    
    return 0;
}
