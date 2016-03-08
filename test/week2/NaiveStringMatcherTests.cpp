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

