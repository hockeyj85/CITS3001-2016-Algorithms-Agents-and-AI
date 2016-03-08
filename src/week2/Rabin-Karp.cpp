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


int rabinKarp(std::string p, std::string t) {
    // Preproccess
    int pHash = 0;
    for (int i = 0; i < p.size(); i++) {
    }

    for (int i = 0; i < (int)(t.length() - p.length()); i++) {
        // filter

        bool match = true;
        for (int j = 0; j < (int)p.length(); j++) {
            if (t[i + j] != p[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return i;
        }
    }
    return -1;
}
