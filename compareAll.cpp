#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace chrono;

// ---------- Merge Sort ----------
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

//Merge sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// ---------- Quick Sort ----------
int helper(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            arr[i] = arr[j];
        }
    }

    arr[i+1] = arr[high];
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = helper(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
// ---------- Binary Search ----------
int binarySearch(const vector<int>& arr, int target) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

// ---------- Exponential Search ----------
int binarySearchExp(const vector<int>& arr, int l, int r, int target) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int exponentialSearch(const vector<int>& arr, int target) {
    if (arr[0] == target) return 0;
    int i = 1;
    while (i < arr.size() && arr[i] <= target) i *= 2;
    return binarySearchExp(arr, i / 2, min(i, (int)arr.size() - 1), target);
}

// ---------- Main Test Function ----------
void testForSize(int size) {
    vector<int> original(size);
    for (int i = 0; i < size; i++)
        original[i] = rand() % 100000;

    // ----- Merge Sort -----
    vector<int> arr1 = original;
    auto start = high_resolution_clock::now();
    mergeSort(arr1, 0, size - 1);
    auto stop = high_resolution_clock::now();
    auto mergeTime = duration_cast<milliseconds>(stop - start).count();

    // ----- Quick Sort -----
    vector<int> arr2 = original;
    start = high_resolution_clock::now();
    quickSort(arr2, 0, size - 1);
    stop = high_resolution_clock::now();
    auto quickTime = duration_cast<milliseconds>(stop - start).count();

    // Ensure sorted array for searching
    vector<int> sortedArr = arr1; // already sorted

    int target = sortedArr.back(); // Worst-case search

    // ----- Binary Search -----
    start = high_resolution_clock::now();
    binarySearch(sortedArr, target);
    stop = high_resolution_clock::now();
    auto binaryTime = duration_cast<milliseconds>(stop - start).count();

    // ----- Exponential Search -----
    start = high_resolution_clock::now();
    exponentialSearch(sortedArr, target);
    stop = high_resolution_clock::now();
    auto expoTime = duration_cast<milliseconds>(stop - start).count();

  
    cout << "Quick Sort for size " << size << ": " << quickTime << " ms\n";
    cout << "Merge Sort for size " << size << ": " << mergeTime << " ms\n";
    cout << "Binary Search for size " << size << ": " << binaryTime << " ms\n";
    cout << "Exponential Search for size " << size << ": " << expoTime << " ms\n";
    cout << "---------------------------------------------------------------\n";
}

int main() {
    srand(time(0));
    vector<int> sizes = {100, 1000, 5000, 10000,15000};

    cout << "---------------------------------------------------------------\n";
    for (int size : sizes) {
        testForSize(size);
    }

    return 0;
}
