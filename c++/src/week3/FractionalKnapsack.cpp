//
// Created by james on 23/03/16.
//

#include "FractionalKnapsack.h"

double fractionalKnapsack(const std::vector<int> weights, const std::vector<int> values, const int capacity) {
    if (values.size() != weights.size() || capacity < 0) {
        throw "Invalid argument exception";
    }
    int nItems = values.size();

    // Make a list of items sorted by value density.
    std::vector<std::pair<double, int> > valueWeights;
    for (int i = 0; i < nItems; i++) {
        double valueDensity = (double)values[i] / (double)weights[i];
        valueWeights.push_back(std::make_pair(valueDensity, i));
    }
    std::sort(valueWeights.begin(), valueWeights.end(), [](std::pair<double, int> a, std::pair<double, int> b) {
        return a.first > b.first;
    });

    // While we have capacity take as many of the items as we can, starting with the highest value density.
    int usedCap = 0, i = 0;
    double usedValue = 0;
    while (usedCap < capacity && i < nItems) {
        int currCap = capacity - usedCap;
        int currVal = values[valueWeights[i].second];
        int currWeight = weights[valueWeights[i].second];

        double fraction = currCap < currWeight ?
                          (double)currCap / (double)currWeight :    // Take a fraction of the item.
                          1;                                        // Take the whole item.

        usedValue += currVal * fraction;
        usedCap += currWeight; // We don't care about saving a fraction of this.

        i++;
    }
    return usedValue;
}