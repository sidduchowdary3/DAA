#include<iostream>
#include<algorithm> // Include the <algorithm> header for std::swap
using namespace std;

int partition(int arr[], int lb, int ub); // Function prototype

void quicksort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int loc = partition(arr, lb, ub);
        quicksort(arr, lb, loc - 1);
        quicksort(arr, loc + 1, ub);
    }
}

int partition(int arr[], int lb, int ub) {
    int start = lb, end = ub, key = arr[lb];
    while (start < end) { 
        while (arr[start] <= key ) { 
            start++;
        }
        while (arr[end] > key) { 
            end--;
        }
        if (start < end) {
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[lb], arr[end]);
    return end;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    int arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quicksort(arr, 0, n - 1);
    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
