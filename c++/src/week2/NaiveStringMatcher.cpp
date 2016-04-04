#include "NaiveStringMatcher.h"

/**
 * Naive String Matcher.
 *
 * James Hockey
 * CITS3001 Lab 1
 *
 * O(|pattern| * |text|)
 *
 * @param p - the pattern to match.
 * @param t - the text to match within.
 */
int naiveStringMatcher(std::string p, std::string t)
{
    for (int i = 0; i < (int)(t.length() - p.length()); i++) {
        bool match = true;
        // maybe skip the for loop
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
