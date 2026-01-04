#include <bits/stdc++.h>

using namespace std;

void manualSwap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    int countLess = 0;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            countLess++;
            i++;
            manualSwap(arr[i], arr[j]);
        }
    }
    manualSwap(arr[i + 1], arr[high]);

    cout << countLess << " element(s) were less than pivot (" << pivot << ")" << endl;

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
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "\n--- Elements Less Than Pivot Trace ---" << endl;
    quickSort(arr, 0, n - 1);

    cout << "\nSorted Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
