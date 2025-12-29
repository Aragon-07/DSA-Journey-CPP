#include <iostream>

using namespace std;

void selectionSortPositives(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Skip if the current element is not positive
        if (arr[i] <= 0) continue;

        int min_idx = i;

        // Look for the minimum positive number in the rest of the array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > 0) { // Only consider positive numbers
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
        }

        // Swap the found minimum positive element with the current positive element
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }

    // Print the result
    cout << "Array after sorting only positives: ";
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
    cout << "Enter " << n << " integers (include negatives and positives):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectionSortPositives(arr, n);

    return 0;
}
