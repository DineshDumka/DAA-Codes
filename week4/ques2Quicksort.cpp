#include <bits/stdc++.h>
using namespace std;

int comparison = 0;
int inversion = 0;

int partition(vector<int>& arr, int start, int end) {
    int pivot = arr[start];
    int i = start;

    for (int j = start + 1; j <= end; j++) {
        comparison++;  // Increment comparisons
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i], arr[start]);
    return i;
}

void quickSort(vector<int>& arr, int start, int end) {
    if (start >= end) return;

    int ind = partition(arr, start, end);
    
    // inversion counting 
    inversion += (ind - start);
    
    quickSort(arr, start, ind - 1);
    quickSort(arr, ind + 1, end);
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    comparison = 0;
    inversion = 0;

    quickSort(arr, 0, n - 1);

    // Display the sorted array
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "inversions: " << inversion << endl;
    cout << "comparisons: " << comparison << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
