#include <iostream>
#include <vector>

using namespace std;

// This function takes the last element as pivot, places it at its correct
// position, and places all smaller to left and larger to right
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1;       // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;
            // Custom swap logic
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Place the pivot in its correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // Return the partition index
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pIndex is the partitioning index, arr[pIndex] is now at right place
        int pIndex = partition(arr, low, high);

        // Separately sort elements before and after partition
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}

int main() {
    vector<int> data = {10, 7, 8, 9, 1, 5};

    quickSort(data, 0, data.size() - 1);

    cout << "Sorted array (Quick Sort): ";
    for (int x : data) cout << x << " ";
    return 0;
}
