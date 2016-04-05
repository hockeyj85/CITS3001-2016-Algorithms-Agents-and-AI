class RabinKarp:

    @staticmethod
    def match(pattern, text):
        "Rabin-Karp pattern matcher, assumes an 8 bit string"

        if len(text) < len(pattern):
            return []

        d = 1 << 8              # alphabet size
        h = pow(d, len(pattern) - 1)  # high order character index for base d number
        q = pow(10, 9) + 7      # large prime
        ph = 0                  # hash of pattern
        th = 0                  # hash of text (sliding window)

        for i in range(len(pattern)):
            ph = (ph * d + ord(pattern[i])) % q
            th = (th * d + ord(text[i])) % q

        matches = []
        for t in range(len(text) - len(pattern) + 1):
            if ph == th:
                matched = True
                for p in range(len(pattern)):
                    if text[t + p] != pattern[p]:
                        matched = False
                        break
                if matched:
                    matches.append(t)
            if t < len(text) - len(pattern):
                th = ((th - ord(text[t]) * h) * d + ord(text[t + len(pattern)])) % q

        return matches
