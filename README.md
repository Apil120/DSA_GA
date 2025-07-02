# DSA Group Project

This repository contains C++ implementations of classic sorting and searching algorithms, designed for academic learning and demonstration purposes. Each algorithm is implemented in a separate file, with interactive console input for user-friendly testing.

## Contents

- `binarySearch.cpp`  
  Implements Quick Sort for sorting and Binary Search for searching a target element in a sorted array.

- `exponentialSearch.cpp`  
  Implements Merge Sort for sorting and Exponential Search (with Binary Search) for searching a target element in a sorted array.

- `mergeSort.cpp`  
  Standalone implementation of Merge Sort for sorting an array.

- `quickSort.cpp`  
  Standalone implementation of Quick Sort for sorting an array.


## How to Compile

You can compile any of the `.cpp` files using `g++` (MinGW on Windows):

```sh
g++ -o output filename.cpp
```

For example, to compile `binarySearch.cpp`:

```sh
g++ -o binSearch binarySearch.cpp
```

## How to Run

After compiling, run the executable from the terminal or command prompt:

```sh
./binSearch.exe
```

Follow the on-screen prompts to enter the array size, elements, and the target value to search (if applicable).

## Algorithms Overview

- **Quick Sort**: Efficient, divide-and-conquer sorting algorithm (used in `binarySearch.cpp` and `quickSort.cpp`).
- **Merge Sort**: Stable, divide-and-conquer sorting algorithm (used in `exponentialSearch.cpp` and `mergeSort.cpp`).
- **Binary Search**: Fast search algorithm for sorted arrays (used in `binarySearch.cpp` and `exponentialSearch.cpp`).
- **Exponential Search**: Quickly finds range for binary search in sorted arrays (used in `exponentialSearch.cpp`).

## Usage Example

```
Enter the size of the array: 5
Enter 5 elements (unsorted): 8 3 1 7 2
Sorted array: 1 2 3 7 8
Enter the target element to search: 7
Element found at index 3
```

## License

This project is for educational purposes.
