#include <iostream>
#include <vector>

using namespace std;

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    int comparisons = 0;
    int swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        // Assume the current position i is the minimum
        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            comparisons++; // Increment comparison count
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        // We only swap if a smaller element was actually found
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            swaps++; // Increment swap count
        }
    }

    // Print sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Print statistics
    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of swaps: " << swaps << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectionSort(arr, n);

    return 0;
}
