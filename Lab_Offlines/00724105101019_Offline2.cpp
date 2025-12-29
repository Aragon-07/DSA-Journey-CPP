#include <bits/stdc++.h>
using namespace std;

struct Book {
    string title;
    string author;
    int year;
};

void selectionSort(vector<Book>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int bestIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].year > arr[bestIdx].year) {
                bestIdx = j;
            }
            else if (arr[j].year == arr[bestIdx].year) {
                if (arr[j].author < arr[bestIdx].author) {
                    bestIdx = j;
                }
                else if (arr[j].author == arr[bestIdx].author) {
                    if (arr[j].title < arr[bestIdx].title) {
                        bestIdx = j;
                    }
                }
            }
        }
        Book temp = arr[i];
        arr[i] = arr[bestIdx];
        arr[bestIdx] = temp;
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    cin.ignore();

    vector<Book> books(n);

    for (int i = 0; i < n; i++) {
        getline(cin, books[i].title, ',');
        cin.ignore();
        getline(cin, books[i].author, ',');
        cin.ignore();
        cin >> books[i].year;
        cin.ignore();
    }

    selectionSort(books);

    for (int i = 0; i < n; i++) {
        cout << books[i].title << ", " << books[i].author << ", " << books[i].year << endl;
    }

    return 0;
}
