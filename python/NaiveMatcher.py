class NaiveMatcher:

    @staticmethod
    def match(P, T):
        "Naive pattern matcher"
        matches = []
        for t in range(len(T) - len(P) + 1):
            matched = True
            for p in range(len(P)):
                if T[t + p] != P[p]:
                    matched = False
                    break
            if matched:
                matches.append(t)
        return matches

