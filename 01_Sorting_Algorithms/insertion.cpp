#include <bits/stdc++.h>
using namespace std;

// Function to perform Insertion Sort on a vector
// We use & to pass by reference so the original vector is sorted
void insertionSort(vector<int>& vec) {
    int n = vec.size();

    for (int i = 1; i < n; i++) {
        int key = vec[i];
        int j = i - 1;

        // Shift elements of vec[0..i-1] that are greater than key
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

// Helper function to print the vector
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Initializing a vector with some values
    vector<int> data = {29, 10, 14, 37, 13};

    cout << "Before sorting: ";
    printVector(data);

    insertionSort(data);

    cout << "After sorting:  ";
    printVector(data);

    return 0;
}
