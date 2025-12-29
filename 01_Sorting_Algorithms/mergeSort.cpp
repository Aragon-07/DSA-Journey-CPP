#include <iostream>
#include <vector>

using namespace std;

// This function merges two sorted halves of the array
void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp; // Temporary vector to store merged elements
    int left = low;      // Starting index of left half
    int right = mid + 1; // Starting index of right half

    // Compare elements from both halves and push the smaller one to temp
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // If elements remain in the left half, add them
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // If elements remain in the right half, add them
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy the sorted elements from temp back into the original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high) return; // Base case: 1 or 0 elements

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);      // Sort left half
    mergeSort(arr, mid + 1, high); // Sort right half
    merge(arr, low, mid, high);    // Merge them together
}

int main() {
    vector<int> data = {38, 27, 43, 3, 9, 82, 10};

    mergeSort(data, 0, data.size() - 1);

    cout << "Sorted array (Merge Sort): ";
    for (int x : data) cout << x << " ";
    return 0;
}
