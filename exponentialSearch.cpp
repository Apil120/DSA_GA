#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int left, int right, int target) {
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

int exponentialSearch(const vector<int>& arr, int target) {
    if (arr[0] == target)
        return 0;

    int n = arr.size();
    int i = 1;
    while (i < n && arr[i] <= target)
        i *= 2;

    return binarySearch(arr, i / 2, min(i, n - 1), target);
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
    int target;
    cout << "\nEnter the target element to search: ";
    cin >> target;

    int result = exponentialSearch(arr,target);
    if (result != -1)
    cout << "Element found at index: " << result ;
    else
    cout << "Element not found";



    return 0;
}
