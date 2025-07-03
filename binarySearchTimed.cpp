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

int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    auto start = high_resolution_clock::now();

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            auto stop = high_resolution_clock::now();
            duration<double> duration_sec = stop - start;
            cout << fixed << "Binary Search Time: " << duration_sec.count() * 1000 << " ms\n";
            return mid;
        } else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    auto stop = high_resolution_clock::now();
    duration<double> duration_sec = stop - start;
    cout << fixed << "Binary Search Time: " << duration_sec.count() * 1000 << " ms\n";

    return -1;
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

    int result = binarySearch(arr, target);
    if (result != -1)
        cout << "Element found at index " << result << "\n";
    else
        cout << "Element not found\n";

    return 0;
}
