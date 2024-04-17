#include <iostream>
#include <vector>
#include <algorithm>  // Required for sort function
using namespace std;

struct item {
    int weight;
    int value;
};

bool compare(item a, item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// This function now returns a pair of double and int, representing total value and total weight, respectively
pair<double, int> greedyKnapsack(vector<item>& items, int capacity) {
    // Sort items based on value-to-weight ratio in descending order
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;  // Total value accumulated
    int currentWeight = 0;    // Current weight in the knapsack

    for (int i = 0; i < items.size(); i++) {
        if (currentWeight + items[i].weight <= capacity) {
            totalValue += items[i].value;
            currentWeight += items[i].weight;
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += (double)remainingCapacity * items[i].value / items[i].weight;
            currentWeight += remainingCapacity;
            break;  // Knapsack is full
        }
    }

    return {totalValue, currentWeight};  // Return both total value and weight
}

int main() {
    int capacity;
    cout << "Enter the capacity: ";
    cin >> capacity;

    cout << "Enter the number of elements: ";
    int numItems;
    cin >> numItems;

    vector<item> items(numItems);
    cout << "Enter weight and value for each item:" << endl;
    for (int i = 0; i < numItems; i++) {
        cin >> items[i].weight >> items[i].value;
    }

    // Retrieve the maximum value and the weight carried
    auto result = greedyKnapsack(items, capacity);
    double maxVal = result.first;
    int maxWeight = result.second;

    cout << "Maximum value: " << maxVal << endl;
    cout << "Maximum weight used: " << maxWeight << endl;
    return 0;
}
