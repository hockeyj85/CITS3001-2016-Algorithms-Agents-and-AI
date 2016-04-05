from KnuthMorrisPratt import KnuthMorrisPratt
from test_benchmarks import TestPatternMatcherBenchmarks
from test_correctness import TestPatternMatcherCorrectness


class TestKnuthMorrisPrattCorrectness(TestPatternMatcherCorrectness):
    matcher = KnuthMorrisPratt

    def test_calculatePrefixFunction(self):
        self.assertEqual(KnuthMorrisPratt.calculate_prefix_function("cocacola"), [0, 0, 1, 0, 1, 2, 0, 0])
        self.assertEqual(KnuthMorrisPratt.calculate_prefix_function("bambam"), [0, 0, 0, 1, 2, 3])
        self.assertEqual(KnuthMorrisPratt.calculate_prefix_function("abcdefg"), [0, 0, 0, 0, 0, 0, 0,])
        self.assertEqual(KnuthMorrisPratt.calculate_prefix_function("aaaaaaa"), [0, 1, 2, 3, 4, 5, 6,])


class TestKnuthMorrisPrattBenchmarks(TestPatternMatcherBenchmarks):
    matcher = KnuthMorrisPratt
