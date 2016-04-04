from unittest import TestCase
from RabinKarp import RabinKarp
import random


class TestRabinKarp(TestCase):

    def test_match_matches_at_beginning(self):
        self.assertEqual(RabinKarp.match("10", "1023151518297"), [0])
        self.assertEqual(RabinKarp.match("what", "whatsupdoc"), [0])
        self.assertEqual(RabinKarp.match("who", "who are you?"), [0])

    def test_match_matches_in_middle(self):
        self.assertEqual(RabinKarp.match("is", "it is a wonderful day today"), [3])
        self.assertEqual(RabinKarp.match("a", "it is a wonderful day today"), [6, 19, 25])
        self.assertEqual(RabinKarp.match("wonderful", "it is a wonderful day today"), [8])
        self.assertEqual(RabinKarp.match("day", "it is a wonderful day today"), [18, 24])

    def test_match_matches_at_end(self):
        self.assertEqual(RabinKarp.match("today", "it is a wonderful day today"), [22])
        self.assertEqual(RabinKarp.match("hi", "oh hi"), [3])
        self.assertEqual(RabinKarp.match("face", "face"), [0])

    def test_match_no_matches(self):
        result = RabinKarp.match("crazy pattern!", "does not exist in this text!")
        self.assertEqual(result, [])
        self.assertEqual(RabinKarp.match("t", "what"), [3])

    def test_match_tens_of_thousands(self):
        T = str(random.getrandbits(10000 * 8))
        P = str(random.getrandbits(5000 * 8))
        self.assertIsNotNone(RabinKarp.match(P,T))

    def test_match_hundereds_of_thousands(self):
        T = str(random.getrandbits(100000 * 8))
        P = str(random.getrandbits(50000 * 8))
        self.assertIsNotNone(RabinKarp.match(P,T))

#    def test_match_millions(self):
#        T = str(random.getrandbits(1000000 * 8))
#        P = str(random.getrandbits(500000 * 8))
#        self.assertIsNotNone(RabinKarp.match(P,T))
