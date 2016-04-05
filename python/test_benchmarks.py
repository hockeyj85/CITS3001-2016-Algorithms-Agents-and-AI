from unittest import TestCase
import random


class TestPatternMatcherBenchmarks(TestCase):
    """
    Some helpers for test benchmarking performance.

    I don't know python but just inherit from this and set self.matcher to the matcher you want to test and it works.
    """
    def run_matcher_random(self, pattern_length, text_length):
        pattern = str(random.getrandbits(pattern_length * 8))
        text = str(random.getrandbits(text_length * 8))
        self.matcher.match(pattern, text)

    def test_random_match_50_100(self):
        TestPatternMatcherBenchmarks.run_matcher_random(self, 50, 100)

    def test_random_match_50_1000(self):
        TestPatternMatcherBenchmarks.run_matcher_random(self, 50, 1000)

    def test_random_match_50_10000(self):
        TestPatternMatcherBenchmarks.run_matcher_random(self, 50, 10000)

    def test_random_match_500_1000(self):
        TestPatternMatcherBenchmarks.run_matcher_random(self, 500, 1000)

    def test_random_match_500_10000(self):
        TestPatternMatcherBenchmarks.run_matcher_random(self, 500, 10000)

#    def test_random_match_5000_10000(self):
#        TestPatternMatcherBenchmarks.run_matcher_random(self, 5000, 10000)
#
#    def test_random_match_5000_100000(self):
#        TestPatternMatcherBenchmarks.run_matcher_random(self, 5000, 100000)

    def run_matcher_same_char(self, pattern_length, text_length):
        pattern = "a" * pattern_length
        text = "a" * text_length
        self.matcher.match(pattern, text)

    def test_same_char_match_50_100(self):
        TestPatternMatcherBenchmarks.run_matcher_same_char(self, 50, 100)

    def test_same_char_match_50_1000(self):
        TestPatternMatcherBenchmarks.run_matcher_same_char(self, 50, 1000)

    def test_same_char_match_50_10000(self):
        TestPatternMatcherBenchmarks.run_matcher_same_char(self, 50, 10000)

    def test_same_char_match_500_1000(self):
        TestPatternMatcherBenchmarks.run_matcher_same_char(self, 500, 1000)

    def test_same_char_match_500_10000(self):
        TestPatternMatcherBenchmarks.run_matcher_same_char(self, 500, 10000)
