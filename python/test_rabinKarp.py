from test_benchmarks import TestPatternMatcherBenchmarks
from test_correctness import TestPatternMatcherCorrectness
from RabinKarp import RabinKarp


class TestRabinKarpCorrectness(TestPatternMatcherCorrectness):
    matcher = RabinKarp


class TestRabinKarpBenchmarks(TestPatternMatcherBenchmarks):
    matcher = RabinKarp
