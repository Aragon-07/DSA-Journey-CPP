#include <iostream>

using namespace std;

void sortMatrixRows(int rows, int cols) {
    // Dynamic allocation or fixed size depends on your lab preference
    // Using a fixed-size or simple array for clarity
    int matrix[rows][cols];

    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Selection Sort on Rows
    for (int i = 0; i < rows - 1; i++) {
        int min_row_idx = i;

        for (int j = i + 1; j < rows; j++) {
            // Compare based on the first element (index 0)
            if (matrix[j][0] < matrix[min_row_idx][0]) {
                min_row_idx = j;
            }
        }

        // Swap the entire rows if a new minimum was found
        if (min_row_idx != i) {
            for (int k = 0; k < cols; k++) {
                int temp = matrix[i][k];
                matrix[i][k] = matrix[min_row_idx][k];
                matrix[min_row_idx][k] = temp;
            }
        }
    }

    // Print the sorted matrix
    cout << "\nMatrix after sorting rows by first element:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int r, c;
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    sortMatrixRows(r, c);

    return 0;
}
