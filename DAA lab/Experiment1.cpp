//Program for recursive linear and binary search
#include <iostream>
#include <vector>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    if (n == 0) {
        return -1; // Key not found
    }
    if (arr[n - 1] == key) {
        return n - 1; // Key found at index n-1
    }
    return linearSearch(arr, n - 1, key); // Search in the remaining array
}

int binarySearch(int arr[], int left, int right, int key) {
    if (left > right) {
        return -1; // Key not found
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == key) {
        return mid; // Key found at index mid
    }
    if (arr[mid] > key) {
        return binarySearch(arr, left, mid - 1, key); // Search in the left half
    }
    return binarySearch(arr, mid + 1, right, key); // Search in the right half
}

int main() {
    int n, key;
    cout << "Enter the number of elements: ";
    cin >> n;
    std::vector<int> arr(n); // replace: int arr[n];
    cout << "Enter the elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the key to search: ";
    cin >> key;

    // Perform linear search
    int linearResult = linearSearch(arr.data(), n, key);
    if (linearResult != -1) {
        cout << "Key found at index (Linear Search): " << linearResult << endl;
    } else {
        cout << "Key not found (Linear Search)" << endl;
    }

    // Perform binary search
    int binaryResult = binarySearch(arr.data(), 0, n - 1, key);
    if (binaryResult != -1) {
        cout << "Key found at index (Binary Search): " << binaryResult << endl;
    } else {
        cout << "Key not found (Binary Search)" << endl;
    }

    return 0;
}

