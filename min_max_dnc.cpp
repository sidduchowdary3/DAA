#include<iostream>
using namespace std;

void max_min(int arr[], int i, int j, int &max1, int &min1) {
    int max2, min2; // Declare variables max2 and min2

    if (i == j) {
        max1 = min1 = arr[i];
    } else if (i == j - 1) {
        if (arr[i] < arr[j]) {
            min1 = arr[i];
            max1 = arr[j];
        } else {
            max1 = arr[i];
            min1 = arr[j]; // Fix assignment of min1
        }
    } else {
        int mid = (i + j) / 2; // Fix calculation of mid
        max_min(arr, i, mid, max1, min1);
        max_min(arr, mid + 1, j, max2, min2); // Fix the variable names
        if (max1 < max2) {
            max1 = max2;
        }
        if (min1 > min2) {
            min1 = min2;
        }
    }
}

int main() {
    int n, arr[100], max1, min1;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    max_min(arr, 0, n - 1, max1, min1);
    cout << "Maximum element: " << max1 << endl;
    cout << "Minimum element: " << min1 << endl;
    return 0;
}
