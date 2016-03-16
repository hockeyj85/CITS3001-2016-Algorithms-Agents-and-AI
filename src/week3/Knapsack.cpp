//
// Created by james on 16/03/16.
//

#include "Knapsack.h"

int knapsack(std::vector<int> weights, std::vector<int> values, int capacity) {
    int W = capacity, I = (int)values.size();
    if (values.size() != weights.size()) throw "Bad inputs";

    int dp[I+1][W+1];

    // Fill with 0's for init.
    for (int i = 0; i <= I; i++) dp[i][0] = 0;
    for (int w = 0; w <= W; w++) dp[0][w] = 0;

    for (int i = 1; i <= I; i++)        // items
    for (int w = 1; w <= W; w++) {      // weights
        int itemWeight = weights[i-1];
        int itemValue = values[i-1];

        int addItemValue = 0;
        if (itemWeight <= w) addItemValue = itemValue + dp[i-1][w-itemWeight];
        int notAddItemValue = dp[i-1][w];

        // Do not add the item if it does not fit.
        if (itemWeight > w) {
            dp[i][w] = notAddItemValue;
        }

        // The item fits, does it increase value?
        else if (addItemValue > notAddItemValue) {
            dp[i][w] = addItemValue;
        }

        // The item fits, but does not add value.
        else if (addItemValue <= notAddItemValue) {
            dp[i][w] = notAddItemValue;
        }

        else {
            throw "This code should never run";
        }
    }
    return dp[I][W];
}

