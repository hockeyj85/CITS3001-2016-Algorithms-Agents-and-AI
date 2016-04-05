from unittest import TestCase


class TestPatternMatcherCorrectness(TestCase):
    """
    Some helpers for testing pattern self.matcher performance.

    I don't know python but just inherit from this and set self.self.matcher to the self.matcher you want to test and it works.
    """

    def test_match_matches_at_beginning(self):
        self.assertEqual(self.matcher.match("10", "1023151518297"), [0])
        self.assertEqual(self.matcher.match("what", "whatsupdoc"), [0])
        self.assertEqual(self.matcher.match("who", "who are you?"), [0])

    def test_match_matches_in_middle(self):
        self.assertEqual(self.matcher.match("is", "it is a wonderful day today"), [3])
        self.assertEqual(self.matcher.match("a", "it is a wonderful day today"), [6, 19, 25])
        self.assertEqual(self.matcher.match("wonderful", "it is a wonderful day today"), [8])
        self.assertEqual(self.matcher.match("day", "it is a wonderful day today"), [18, 24])

    def test_match_matches_at_end(self):
        self.assertEqual(self.matcher.match("today", "it is a wonderful day today"), [22])
        self.assertEqual(self.matcher.match("hi", "oh hi"), [3])
        self.assertEqual(self.matcher.match("face", "face"), [0])

    def test_match_repeated_pattern(self):
        self.assertEqual(self.matcher.match("a", "aaaaaaaaa"), [0, 1, 2, 3, 4, 5, 6, 7, 8, ])
        self.assertEqual(self.matcher.match("aa", "aaaaaaaaa"), [0, 1, 2, 3, 4, 5, 6, 7, ])
        self.assertEqual(self.matcher.match("aaa", "aaaaaaaaa"), [0, 1, 2, 3, 4, 5, 6, ])
        self.assertEqual(self.matcher.match("aaaa", "aaaaaaaaa"), [0, 1, 2, 3, 4, 5, ])
        self.assertEqual(self.matcher.match("aaaaa", "aaaaaaaaa"), [0, 1, 2, 3, 4, ])
        self.assertEqual(self.matcher.match("aaaaaa", "aaaaaaaaa"), [0, 1, 2, 3, ])
        self.assertEqual(self.matcher.match("aaaaaaa", "aaaaaaaaa"), [0, 1, 2, ])
        self.assertEqual(self.matcher.match("aaaaaaaa", "aaaaaaaaa"), [0, 1, ])
        self.assertEqual(self.matcher.match("aaaaaaaaa", "aaaaaaaaa"), [0, ])
        self.assertEqual(self.matcher.match("aaaaaaaaaa", "aaaaaaaaa"), [])

    def test_match_no_matches(self):
        result = self.matcher.match("crazy pattern!", "does not exist in this text!")
        self.assertEqual(result, [])
        self.assertEqual(self.matcher.match("t", "what"), [3])
