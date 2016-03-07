#include "Rabin-Karp.h"

/**
 * Rabin-Karp string matching.
 *
 * Speeds up the inner loop of the naive method by converting patterns words,
 * which can be compared in constant time.
 *
 * Some sneaky maths allows us to generate this in O(n).
 *
 * We can use it to filter out to avoid *most* comparisons.
 * In the worst case this is not better than naive. Expected is better though.
 * Let's write it and test it.
 */


int rabinKarp(std::string pattern, std::string text) {
    throw "Not yet implemented";
}
