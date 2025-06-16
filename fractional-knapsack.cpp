#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool custom_comparator(pair<int, int> a, pair<int, int> b) {
    double v1 = (double)a.first / a.second;
    double v2 = (double)b.first / b.second;
    return v1 > v2;
}

double fractional_knapsack(vector<pair<int, int>> items, int w) {
    sort(items.begin(), items.end(), custom_comparator);
    
    double totalValue = 0.0;

    for (auto item : items) {
        int value = item.first;
        int weight = item.second;

        if (w >= weight) {
            totalValue += value;
            w -= weight;
        } else {
            // take fraction
            totalValue += ((double)value / weight) * w;
            break;
        }
    }

    return totalValue;
}

int main() {
    vector<pair<int, int>> items = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;

    double maxValue = fractional_knapsack(items, capacity);
    cout << "Maximum value: " << maxValue << endl;

    return 0;
}
