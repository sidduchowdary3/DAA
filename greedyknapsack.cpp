#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct item {
    int weight;
    int value;
    int index;
};

bool compare(item a, item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

pair<pair<double, int>, vector<pair<int, double>>> greedyKnapsack(vector<item>& items, int capacity) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int currentWeight = 0;
    vector<pair<int, double>> solution;

    for (int i = 0; i < items.size(); i++) {
        if (currentWeight + items[i].weight <= capacity) {
            totalValue += items[i].value;
            currentWeight += items[i].weight;
            solution.push_back(make_pair(items[i].index, 1));
        } else {
            int remainingCapacity = capacity - currentWeight;
            double fraction = (double)remainingCapacity / items[i].weight;
            totalValue += remainingCapacity * items[i].value / items[i].weight;
            currentWeight += remainingCapacity;
            solution.push_back(make_pair(items[i].index, fraction));
            break;
        }
    }

    return {{totalValue, currentWeight}, solution};
}

int main() {
    int capacity;
    cout << "Enter the capacity: ";
    cin >> capacity;

    cout << "Enter the number of elements: ";
    int numItems;
    cin >> numItems;

    vector<item> items(numItems);
    cout << "Enter weight and value for each item:";
    for (int i = 0; i < numItems; i++) {
        cin >> items[i].weight >> items[i].value;
        items[i].index = i;
    }

    auto result = greedyKnapsack(items, capacity);
    double maxVal = result.first.first;
    int maxWeight = result.first.second;
    auto solution = result.second;

    cout << "Maximum value: " << maxVal << endl;
    cout << "Maximum weight used: " << maxWeight << endl;
    cout << "Items included (index and fraction):";
    for (auto& s : solution) {
        cout << "Item " << s.first << " included fraction: " << s.second << endl;
    }
    return 0;
}
