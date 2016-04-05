from NaiveMatcher import NaiveMatcher
from test_benchmarks import TestPatternMatcherBenchmarks
from test_correctness import TestPatternMatcherCorrectness


class TestNaiveMatcherCorrectness(TestPatternMatcherCorrectness):
    matcher = NaiveMatcher


class TestNaiveMatcherBenchmarks(TestPatternMatcherBenchmarks):
    matcher = NaiveMatcher
