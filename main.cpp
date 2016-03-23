#include <iostream>
#include "src/week3/Knapsack.h"
#include "src/week3/FractionalKnapsack.h"

/**
 * Sandbox file for playing around with library functions.
 */

using namespace std;

int main()
{
    vector<int> weights = { 1, 2, 3 };
    vector<int> values = { 2, 8, 16 };
    int capacity = 3;

    int val = knapsack(weights, values, capacity);
    cout << "Hello, World! " << val << endl;

    double val1 = fractionalKnapsack(weights, values, capacity);
    cout << "Hello, World! " << val1 << endl;
    return 0;
}