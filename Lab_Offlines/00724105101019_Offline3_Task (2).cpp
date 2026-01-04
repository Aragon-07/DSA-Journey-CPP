#include <bits/stdc++.h>

using namespace std;

int comparisonCount = 0;

void manualSwap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        comparisonCount++;
        if (arr[j] < pivot) {
            i++;
            manualSwap(arr[i], arr[j]);
        }
    }
    manualSwap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter the number of integers (N): ";
    if (!(cin >> n)) return 0;

    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nTotal number of comparisons: " << comparisonCount << endl;

    return 0;
}
