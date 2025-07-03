#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <iomanip>

using namespace std;
using namespace chrono;

// ---------- Merge Sort ----------
void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size())
        arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// ---------- Quick Sort ----------
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    vector<int> sizes = {100, 1000, 5000, 10000};

    cout << "---------------------------------------------------------------\n";
    for (int size : sizes) {
        testForSize(size);
    }

    return 0;
}
