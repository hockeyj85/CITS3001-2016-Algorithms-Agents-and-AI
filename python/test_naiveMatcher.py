from unittest import TestCase
from NaiveMatcher import NaiveMatcher
import random


class TestNaiveMatcher(TestCase):

    def test_match_matches_at_beginning(self):
        result = NaiveMatcher.match("it", "it is a wonderful day today")
        self.assertEqual(result, [0])

    def test_match_matches_in_middle(self):
        result = NaiveMatcher.match("is", "it is a wonderful day today")
        self.assertEqual(result, [3])

    def test_match_matches_at_end(self):
        result = NaiveMatcher.match("today", "it is a wonderful day today")
        self.assertEqual(result, [22])

    def test_match_no_matches(self):
        result = NaiveMatcher.match("crazy pattern!", "does not exist in this text!")
        self.assertEqual(result, [])
        self.assertEqual(NaiveMatcher.match("t", "what"), [3])

    def test_match_tens_of_thousands(self):
        T = str(random.getrandbits(10000 * 8))
        P = str(random.getrandbits(5000 * 8))
        self.assertIsNotNone(NaiveMatcher.match(P,T))

    def test_match_hundereds_of_thousands(self):
        T = str(random.getrandbits(100000 * 8))
        P = str(random.getrandbits(50000 * 8))
        self.assertIsNotNone(NaiveMatcher.match(P,T))

#    def test_match_millions(self):
#        T = str(random.getrandbits(1000000 * 8))
#        P = str(random.getrandbits(500000 * 8))
#        self.assertIsNotNone(NaiveMatcher.match(P,T))
