#include <iostream>

using namespace std;

void selectionSortEvenIndices(int arr[], int n) {
    // Outer loop: start at 0, move by 2 to stay on even indices
    for (int i = 0; i < n - 1; i += 2) {
        int min_idx = i;

        // Inner loop: look ahead only at even indices
        for (int j = i + 2; j < n; j += 2) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum with the current even index
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }

    // Print the result
    cout << "Array after sorting even indices: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectionSortEvenIndices(arr, n);

    return 0;
}
