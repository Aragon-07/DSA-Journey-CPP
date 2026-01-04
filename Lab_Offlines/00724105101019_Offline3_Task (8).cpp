#include <bits/stdc++.h>

using namespace std;

void findMedian(vector<int> &arr1, vector<int> &arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> merged(n1 + n2);

    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    while (i < n1) {
        merged[k++] = arr1[i++];
    }

    while (j < n2) {
        merged[k++] = arr2[j++];
    }

    cout << "Merged array: ";
    for (int x : merged) {
        cout << x << " ";
    }
    cout << endl;

    int total = n1 + n2;
    if (total % 2 != 0) {
        cout << "Median: " << merged[total / 2] << endl;
    } else {
        double median = (merged[(total / 2) - 1] + merged[total / 2]) / 2.0;
        cout << "Median: " << median << endl;
    }
}

int main() {
    int n1, n2;
    cout << "Enter size of first sorted array: ";
    cin >> n1;
    vector<int> arr1(n1);
    cout << "Enter elements: ";
    for (int i = 0; i < n1; i++) cin >> arr1[i];

    cout << "Enter size of second sorted array: ";
    cin >> n2;
    vector<int> arr2(n2);
    cout << "Enter elements: ";
    for (int i = 0; i < n2; i++) cin >> arr2[i];

    findMedian(arr1, arr2);

    return 0;
}
