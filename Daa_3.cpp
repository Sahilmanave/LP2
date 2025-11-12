#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>  // for fixed and setprecision
using namespace std;

// Structure for each item
struct Item {
    int value, weight;
    double ratio;
};

// Compare items by value/weight ratio (descending)
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

// Fractional Knapsack function
pair<double, vector<double>> fractionalKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compare);

    double max_value = 0.0;
    vector<double> fractions(items.size(), 0.0);

    for (int i = 0; i < items.size(); i++) {
        if (items[i].weight <= capacity) {
            fractions[i] = 1.0;  // take full item
            max_value += items[i].value;
            capacity -= items[i].weight;
        } else {
            fractions[i] = (double)capacity / items[i].weight;  // take fraction
            max_value += items[i].value * ((double)capacity / items[i].weight);
            break;
        }
    }

    return {max_value, fractions};
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
        cin >> items[i].value;

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
        cin >> items[i].weight;

    cout << "Enter maximum weight: ";
    cin >> capacity;

    // calculate ratio for each item
    for (int i = 0; i < n; i++)
        items[i].ratio = (double)items[i].value / items[i].weight;

    auto result = fractionalKnapsack(items, capacity);
    double max_value = result.first;
    vector<double> fractions = result.second;

    cout << fixed << setprecision(4);
    cout << "\nMaximum value that can be carried: " << max_value << endl;

    cout << "Fractions of items taken: [";
    for (int i = 0; i < n; i++) {
        cout << fractions[i];
        if (i != n - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
