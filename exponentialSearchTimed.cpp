#include <iostream>
#include <vector>
#include <chrono> 
using namespace std;
using namespace chrono;

int helper(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = helper(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int binarySearch(vector<int>& arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Exponential search with chrono
int exponentialSearch(vector<int>& arr, int target) {
    auto start = high_resolution_clock::now();

    if (arr[0] == target) {
        auto stop = high_resolution_clock::now();
        duration<double> duration_sec = stop - start;
        cout << fixed << "Exponential Search Time: " << duration_sec.count() * 1000 << " ms\n";
        return 0;
    }

    int n = arr.size();
    int i = 1;
    while (i < n && arr[i] <= target)
        i *= 2;

    int result = binarySearch(arr, i / 2, min(i, n - 1), target);

    auto stop = high_resolution_clock::now();
    duration<double> duration_sec = stop - start;
    cout << fixed << "Exponential Search Time: " << duration_sec.count() * 1000 << " ms\n";

    return result;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements (unsorted): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    int target;
    cout << "\nEnter the target element to search: ";
    cin >> target;

    int result = exponentialSearch(arr, target);
    if (result != -1)
        cout << "Element found at index: " << result << "\n";
    else
        cout << "Element not found\n";

    return 0;
}
