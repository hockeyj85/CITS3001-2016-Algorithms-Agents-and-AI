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
        int textLength = t.textLength;
        char *textCharArr = new char[textLength];
        for (int i = 0; i < textLength; i++) {
            // Use lowercase letters
            textCharArr[i] = i % 1;// (char) rand() % 1; //  (i % ('z' - 'a')) + 'a';
        }
        text = new std::string(textCharArr, textLength);

        // Generate pattern that *almost* matches.
        int patternLength = t.patternLength;
        char *patternCharArr = new char[patternLength];
        for (int i = 0; i < patternLength; i++) {
            // Use lowercase letters
            patternCharArr[i] = i % 1;//(char) rand() % 1; //(i % ('z' - 'a')) + 'a';
        }
        patternCharArr[patternLength - 1] = 101;
        pattern = new std::string(patternCharArr, patternLength);
    }

    void TearDown() {
        delete text;
        delete pattern;
    }
};


TEST_P(MatcherBenchmark, AlmostMatch) {
    MatcherTestInfo t = GetParam();
    int patternIndex = t.f_stringMatcher(*text, *pattern);
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
