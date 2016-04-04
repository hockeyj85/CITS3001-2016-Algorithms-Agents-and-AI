//
// Created by james on 8/03/16.
//

#include "gtest/gtest.h"
#include "Rabin-Karp.h"
#include <string>

TEST(RabinKarpTest, MatchAtStart) {
    int result = rabinKarp("beer", "beer is great");
    EXPECT_EQ(0, result);
}

TEST(RabinKarpTest, MatchInMiddle) {
    int result = rabinKarp("is", "beer is great");
    EXPECT_EQ(5, result);
}

TEST(RabinKarpTest, MatchOffEnd) {
    int result = rabinKarp("great", "beer is grea");
    EXPECT_EQ(-1, result);
}

TEST(RabinKarpTest, MatchOffBeginning) {
    int result = rabinKarp("fbeer", "beer is grea");
    EXPECT_EQ(-1, result);
}

