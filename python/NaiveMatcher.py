class NaiveMatcher:

    @staticmethod
    def match(pattern, text):
        """Naive pattern matcher"""

        if len(pattern) > len(text):
            return []

        matches = []
        for t in range(len(text) - len(pattern) + 1):
            matched = True
            for p in range(len(pattern)):
                if text[t + p] != pattern[p]:
                    matched = False
                    break
            if matched:
                matches.append(t)
        return matches
