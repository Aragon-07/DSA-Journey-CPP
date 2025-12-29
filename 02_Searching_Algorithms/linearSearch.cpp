#include <bits/stdc++.h>
using namespace std;

// Manual Linear Search
// Time Complexity: O(N)
int manualLinearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int data[] = {10, 20, 30, 40, 50};
    int n = sizeof(data)/sizeof(data[0]);
    int target = 30;

    int result = manualLinearSearch(data, n, target);

    if(result != -1) cout << "Element found at index: " << result << endl;
    else cout << "Element not found." << endl;

    return 0;
}
