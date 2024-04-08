#include<iostream>
using namespace std;

void merge(int arr[], int lb, int mid, int ub) {
    int i = lb, j = mid + 1, k = 0;
    int brr[100]; // Moved the declaration outside the loop

    while (i <= mid && j <= ub) {
        if (arr[i] < arr[j]) {
            brr[k] = arr[i];
            i++;
        }
        else {
            brr[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        brr[k] = arr[i];
        i++;
        k++;
    }

    while (j <= ub) {
        brr[k] = arr[j];
        j++;
        k++;
    }

    // Copy elements from brr back to arr
    for (int x = 0; x < k; x++) {
        arr[lb + x] = brr[x];
    }
}

void mergesort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergesort(arr, lb, mid);
        mergesort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergesort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
