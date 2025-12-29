#include <iostream>

using namespace std;

void findKthSmallest(int arr[], int n, int k) {
    // Basic validation
    if (k < 1 || k > n) {
        cout << "Invalid value of k!" << endl;
        return;
    }

    // We only need to run the outer loop k times
    for (int i = 0; i < k; i++) {
        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum to the i-th position
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }

    // The k-th smallest element is now at index k-1
    cout << "The " << k << "-th smallest element is: " << arr[k - 1] << endl;
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter k: ";
    cin >> k;

    findKthSmallest(arr, n, k);

    return 0;
}
