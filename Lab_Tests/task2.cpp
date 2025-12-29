#include <iostream>

using namespace std;

void selectionSortWithKSwaps(int arr[], int n, int k) {
    int swapsPerformed = 0;

    for (int i = 0; i < n - 1; i++) {
        // If we have already reached k swaps, we stop the sorting process
        if (swapsPerformed >= k) {
            break;
        }

        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Only swap if a smaller element was found
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;

            swapsPerformed++;
        }
    }

    // Print the array after performing at most k swaps
    cout << "Array after " << swapsPerformed << " swaps: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the maximum number of swaps (k): ";
    cin >> k;

    selectionSortWithKSwaps(arr, n, k);

    return 0;
}
