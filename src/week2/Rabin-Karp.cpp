#include "Rabin-Karp.h"
#include <cmath>

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

const int PRIME = 1000000007;
const int ALPHABET_SIZE = 1 << 8;

// Naive modular exponentiation.
int modPow(int base, int exp, int mod) {
    if (mod == 1) return 0;
    int c = base;
    // i represents the power of base at the start of the loop.
    for (int i = 1; i < exp; i++) {
        c = (c * c) % mod;
    }
    return c;
}

int rabinKarp(std::string P, std::string T) {

    int q = PRIME;
    int d = ALPHABET_SIZE;
    int n = (int)T.size();      // Text length
    int m = (int)P.size();      // Pattern Length
    int h = modPow(d, m-1, q);  // Position of high order bit
    int p = 0;                  // Pattern hash
    int t = 0;                  // Text hash

    // Preprocess: get starting hashes.
    for (int i = 0; i < m; i++) {
        p = (((d * p) % q) + P[i]) % q;
        t = (((d * t) % q) + T[i]) % q;
    }

    // Matching
    for (int s = 0; s < n - m; s++) {
        if (p == t) {
            // Naive check
            bool match = true;
            for (int i = 0; i < m; i++) {
                if (T[s + i] != P[i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return s;
            }
        }
        // Recalculate hash for text in constant time.
        if (s < n - m) {
            t = ((d * (t - T[s] * h) % q) % q) + T[s + m] % q;
        }
    }
    return -1;
}
