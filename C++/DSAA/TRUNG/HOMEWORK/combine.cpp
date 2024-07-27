// INCLUDE LIBRARY
#include <bits/stdc++.h>
using namespace std;

// SELECTION SORT FUNCTION
void selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        swap(a[min_idx], a[i]);
    }
}

// MAIN FUNCTION
int main() {
    const int SIZE = 100000; // 10 triệu phần tử

    // Initialize arrays
    int* a1 = new int[SIZE];
    int* a2 = new int[SIZE];

    // Fill the array with random numbers
    srand(time(0)); // Seed the random number generator
    for (int i = 0; i < SIZE; i++) {
        int num = rand() % 100000; // Random number between 0 and 100 triệu
        a1[i] = num;
        a2[i] = num;
    }

    // Measure time for Selection Sort
    clock_t start_time = clock();
    selection_sort(a1, SIZE);
    clock_t end_time = clock();
    double selection_sort_time = double(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Selection Sort time: " << selection_sort_time << " seconds" << endl;

    // Measure time for std::sort
    start_time = clock();
    sort(a2, a2 + SIZE);
    end_time = clock();
    double std_sort_time = double(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "std::sort time: " << std_sort_time << " seconds" << endl;

    // Cleanup
    delete[] a1;
    delete[] a2;

    return 0;
}
