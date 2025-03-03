#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[high]);

    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

int quickselect(vector<int>& arr, int low, int high, int k) {
    if (low == high) return arr[low];

    int pivotIndex = partition(arr, low, high);

    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickselect(arr, low, pivotIndex - 1, k);
    } else {
        return quickselect(arr, pivotIndex + 1, high, k);
    }
}

int main() {
    srand(time(0));

    vector<int> arr = {12, 3, 5, 7, 19, 2, 8};
    int k = 3;

    int result = quickselect(arr, 0, arr.size() - 1, k - 1);

    cout << "The " << k << "-th smallest element is " << result << endl;

    return 0;
}
