#include <iostream>
#include <vector>

using namespace std;

void manualSwap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &vec, int start, int end, int pivotValue = -1) {
    if (pivotValue != -1) {
        for (int i = start; i <= end; i++) {
            if (vec[i] == pivotValue) {
                manualSwap(vec[i], vec[end]);
                break;
            }
        }
    }

    int pivot = vec[end];
    int idx = start - 1;

    for (int i = start; i < end; i++) {
        if (vec[i] < pivot) {
            idx++;
            manualSwap(vec[i], vec[idx]);
        }
    }
    idx++;
    manualSwap(vec[end], vec[idx]);
    return idx;
}

void Quick_sort(vector<int> &vec, int start, int end) {
    if (start < end) {
        int pivotIdx = partition(vec, start, end);

        Quick_sort(vec, start, pivotIdx - 1);
        Quick_sort(vec, pivotIdx + 1, end);
    }
}

int main() {
    int n, chosenPivot;
    cout << "Enter the array size: ";
    cin >> n;

    vector<int> vec;
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vec.push_back(x);
    }

    cout << "Enter the pivot value to start with: ";
    cin >> chosenPivot;

    int pIdx = partition(vec, 0, n - 1, chosenPivot);

    Quick_sort(vec, 0, pIdx - 1);
    Quick_sort(vec, pIdx + 1, n - 1);

    cout << "Fully sorted array: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
