#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key, int &comparisons) {
    
    return -1;
}

void searchInSortedArray(int arr[], int n, int key) {
    int comparisons = 0;
    int result = binarySearch(arr, 0, n - 1, key, comparisons);
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
        
        int comparisons = 0, result = -1;
        int low = 0, high = n-1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            comparisons++;
            if (arr[mid] == key){
                result =  mid;
                break;
            }
            else if (arr[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }
        if (result != -1)
        cout << "Present " << comparisons << endl;
        else
            cout << "Not Present " << comparisons << endl;
    }

    return 0;
}
