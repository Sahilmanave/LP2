#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    int value, weight;
};

// Compare items by value/weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) cin >> items[i].value;

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) cin >> items[i].weight;

    cout << "Enter maximum weight: ";
    cin >> capacity;

    // Sort items by value/weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    vector<double> fraction(n, 0.0);

    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            fraction[i] = 1.0;
            capacity -= items[i].weight;
        } else {
            double part = (double)capacity / items[i].weight;
            totalValue += items[i].value * part;
            fraction[i] = part;
            capacity = 0;
        }
    }

    cout << fixed << setprecision(4);
    cout << "\nMaximum value that can be carried: " << totalValue << endl;
    cout << "Fractions of items taken: [";
    for (int i = 0; i < n; i++) {
        cout << fraction[i];
        if (i != n - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
