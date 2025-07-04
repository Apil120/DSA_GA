#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <iomanip>
using namespace std;
using namespace chrono;

void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> L(arr.begin() + l, arr.begin() + m + 1);
    vector<int> R(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < L.size() && j < R.size())
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < L.size()) arr[k++] = L[i++];
    while (j < R.size()) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

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

void testForSize(int size) {
    vector<int> original(size);
    for (int i = 0; i < size; i++)
        original[i] = rand() % 100000;

    vector<int> arr1 = original;
    auto start = high_resolution_clock::now();
    mergeSort(arr1, 0, size - 1);
    auto stop = high_resolution_clock::now();
    duration<double> mergeTime = stop - start;

    vector<int> arr2 = original;
    start = high_resolution_clock::now();
    quickSort(arr2, 0, size - 1);
    stop = high_resolution_clock::now();
    duration<double> quickTime = stop - start;

    vector<int> sortedArr = arr1;
    int target = sortedArr.back();
    volatile int result;

    int trials = 10000;
    duration<double> totalBinary(0), totalExpo(0);

    for (int i = 0; i < trials; i++) {
        start = high_resolution_clock::now();
        result = binarySearch(sortedArr, target);
        stop = high_resolution_clock::now();
        totalBinary += stop - start;

        start = high_resolution_clock::now();
        result = exponentialSearch(sortedArr, target);
        stop = high_resolution_clock::now();
        totalExpo += stop - start;
    }

    // CSV format: input,merge,quick,binary,exponential
    cout << size << "," 
         << fixed << setprecision(6)
         << mergeTime.count() << ","
         << quickTime.count() << ","
         << (totalBinary.count() / trials) << ","
         << (totalExpo.count() / trials) << "\n";
}

int main() {
    srand(time(0));
    vector<int> sizes = {10, 100, 1000, 10000, 25000, 50000, 75000, 100000};

    cout << "Input Size,Merge Sort (s),Quick Sort (s),Binary Search (s),Exponential Search (s)\n";
    for (int size : sizes) {
        testForSize(size);
    }

    return 0;
}
