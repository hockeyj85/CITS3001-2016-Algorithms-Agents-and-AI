//
// Created by james on 7/03/16.
//

#include "gtest/gtest.h"
#include "NaiveStringMatcher.h"

TEST(NaiveMatcherTest, MatchAtStart) {
    int result = naiveStringMatcher("beer", "beer is great");
    EXPECT_EQ(0, result);
}

TEST(NaiveMatcherTest, MatchInMiddle) {
    int result = naiveStringMatcher("is", "beer is great");
    EXPECT_EQ(5, result);
}

TEST(NaiveMatcherTest, MatchOffEnd) {
    int result = naiveStringMatcher("great", "beer is grea");
    EXPECT_EQ(-1, result);
}

TEST(NaiveMatcherTest, MatchOffBeginning) {
    int result = naiveStringMatcher("fbeer", "beer is grea");
    EXPECT_EQ(-1, result);
}

/**
 * Run string matcher on a string that will never match
 * expects to return -1.
 */
int runNaiveMatcher(int textLength, int patternLength) {
    char *str = new char[textLength];
    for (int i = 0; i < textLength; i++) {
        // Use lowercase letters
        str[i] = (char) (i % ('z' - 'a')) + 'a';
    }
    char *pat = new char[patternLength];
    for (int i = 0; i < patternLength; i++) {
        // Use lowercase letters
        pat[i] = (char) (i % ('z' - 'a')) + 'a';
    }
    pat[patternLength - 1] = 'A';

    return naiveStringMatcher(pat, str);
}


TEST(NaiveMatcherTest, Len1000String) {
    int result = runNaiveMatcher(1000, 100);
    EXPECT_EQ(-1, result);
}

TEST(NaiveMatcherTest, Len10000String) {
    int result = runNaiveMatcher(10000, 100);
    EXPECT_EQ(-1, result);
}

TEST(NaiveMatcherTest, Len100000String) {
    int result = runNaiveMatcher(100000, 1000);
    EXPECT_EQ(-1, result);
}

TEST(NaiveMatcherTest, Len1000000String) {
    int result = runNaiveMatcher(1000000, 1000);
    EXPECT_EQ(-1, result);
}

TEST(NaiveMatcherTest, Len10000000String_smallPattern) {
    int result = runNaiveMatcher(10000000, 10);
    EXPECT_EQ(-1, result);
}

TEST(NaiveMatcherTest, Len10000000String_medPattern) {
    int result = runNaiveMatcher(10000000, 100);
    EXPECT_EQ(-1, result);
}

TEST(NaiveMatcherTest, Len10000000String_largePattern) {
    int result = runNaiveMatcher(10000000, 10000);
    EXPECT_EQ(-1, result);
}

TEST(NaiveMatcherTest, Len100000000String_smallPattern) {
    int result = runNaiveMatcher(100000000, 10);
    EXPECT_EQ(-1, result);
}

TEST(NaiveMatcherTest, Len100000000String_medPattern) {
    int result = runNaiveMatcher(100000000, 100);
    EXPECT_EQ(-1, result);
}
