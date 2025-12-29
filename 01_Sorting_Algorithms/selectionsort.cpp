#include <iostream>
#include <vector>

using namespace std;

// Function to perform Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();

    // One by one move the boundary of the unsorted subarray
    for (int i = 0; i < n - 1; i++) {

        // Find the minimum element in the unsorted part [i...n-1]
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update minIndex if a smaller element is found
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        // We only swap if the minIndex actually changed
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Function to print the array
void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> data = {29, 10, 14, 37, 13};

    cout << "Original array: ";
    printArray(data);

    selectionSort(data);

    cout << "Sorted array: ";
    printArray(data);

    return 0;
}
