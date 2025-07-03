#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib> // For rand()
#include <ctime>   // For time()

using namespace std;
using namespace std::chrono;

// Helper function for quick sort
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

// Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = helper(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    // Seed random number generator
    srand(time(0));

    // Fill array with random integers from 1 to 100000
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000 + 1;
    }

    // Measure time using chrono
    auto start = high_resolution_clock::now();

    quickSort(arr, 0, n - 1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "\nInput size: " << n << endl;
    cout << "Time taken by Quick Sort: " << duration.count() << " milliseconds\n";

    return 0;
}
