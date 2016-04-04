//
// Created by james on 8/03/16.
//

#include <functional>
#include "gtest/gtest.h"
#include "NaiveStringMatcher.h"
#include "Rabin-Karp.h"

struct MatcherTestInfo {
    int patternLength;
    int textLength;
    std::function<int(std::string pattern, std::string text)> f_stringMatcher;
};

/**
 * Set up benchmark test data.
 */
class MatcherBenchmark : public ::testing::TestWithParam<MatcherTestInfo> {
public: std::string *text, *pattern;

    void SetUp() {
        MatcherTestInfo t = GetParam();

        // Generate text
        char *tText = new char[t.textLength];
        for (int i = 0; i < t.textLength; i++) {
            // Use lowercase letters
            tText[i] = i % 128;
        }
        text = new std::string(tText, t.textLength);
        delete[] tText;

        // Generate pattern that *almost* matches.
        char *tPattern = new char[t.patternLength];
        for (int i = 0; i < t.patternLength; i++) {
            // Use lowercase letters
            tPattern[i] = i % 128;
        }
        tPattern[t.patternLength - 1] = 102;
        pattern = new std::string(tPattern, t.patternLength);
        delete[] tPattern;
    }

    void TearDown() {
        delete text;
        delete pattern;
    }
};


TEST_P(MatcherBenchmark, AlmostMatch) {
    MatcherTestInfo t = GetParam();
    int patternIndex = t.f_stringMatcher(*text, *pattern);
    // Sanity check
    EXPECT_EQ(-1, patternIndex);
}

std::function<int(std::string p, std::string t)> f_naive = naiveStringMatcher;
std::vector<MatcherTestInfo> naiveTests = {
        {100,       1000,       f_naive},
        {100,       10000,      f_naive},
        {5000,      10000,      f_naive},
        {50000,     100000,     f_naive},
        {500000,    1000000,    f_naive},
        {5000000,   10000000,   f_naive},
        {50000000,  100000000,  f_naive},
        {500000000, 1000000000, f_naive},
//        {5000000000,10000000000,    f_naive},
};

INSTANTIATE_TEST_CASE_P(NaiveMatcher, MatcherBenchmark, ::testing::ValuesIn(naiveTests) );

std::function<int(std::string p, std::string t)> r_RabinKarp = rabinKarp;
std::vector<MatcherTestInfo> rabinKarpTests = {
        {100,       1000,       r_RabinKarp},
        {100,       10000,      r_RabinKarp},
        {5000,      10000,      r_RabinKarp},
        {50000,     100000,     r_RabinKarp},
        {500000,    1000000,    r_RabinKarp},
        {5000000,   10000000,   r_RabinKarp},
        {50000000,  100000000,  r_RabinKarp},
        {500000000, 1000000000, r_RabinKarp},
};

INSTANTIATE_TEST_CASE_P(RabinKarp, MatcherBenchmark, ::testing::ValuesIn(rabinKarpTests) );
