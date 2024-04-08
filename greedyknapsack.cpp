#include <iostream>
#include <vector>
#include <algorithm> // Required for sort function
using namespace std;

struct item {
    int weight;
    int value;
}; // Add semicolon at the end of struct definition

bool compare(item a, item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double greedyknapssack(vector<item>& arr, int n) { // Change return type to double
    sort(arr.begin(), arr.end(), compare);
    double tv = 0.0;
    int cw = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (cw + arr[i].weight <= n) { // Correct the condition
            tv += arr[i].value;
            cw += arr[i].weight;
        } else {
            int rem = n - cw;
            tv += (double)rem * arr[i].value / arr[i].weight;
            break;
        }
    }
    return tv; // Return the total value
}

int main() {
    int n;
    cout << "Enter the capacity: ";
    cin >> n;
    cout << "Enter the number of elements: ";
    int numItems;
    cin >> numItems;
    vector<item> arr(numItems); // Declare arr as a vector of item
    cout << "Enter weight and value for each item:" << endl;
    for (int i = 0; i < numItems; i++) {
        cin >> arr[i].weight >> arr[i].value;
    }
    double maxval = greedyknapssack(arr, n); // Pass vector instead of array
    cout << "Maximum value: " << maxval << endl;
    return 0;
}
