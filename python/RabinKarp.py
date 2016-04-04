class RabinKarp:

    @staticmethod
    def match(P, T):
        "Rabin-Karp pattern matcher, assumes an 8 bit string"

        d = 1 << 8              # alphabet size
        h = pow(d, len(P) - 1)  # high order character index for base d number
        q = pow(10, 9) + 7      # large prime
        ph = 0                  # hash of pattern
        th = 0                  # hash of text (sliding window)

        for i in range(len(P)):
            ph = (ph * d + ord(P[i])) % q
            th = (th * d + ord(T[i])) % q

        matches = []
        for t in range(len(T) - len(P) + 1):
            if ph == th:
                matched = True
                for p in range(len(P)):
                    if T[t + p] != P[p]:
                        matched = False
                        break
                if matched:
                    matches.append(t)
            if t < len(T) - len(P):
                th = ((th - ord(T[t]) * h) * d + ord(T[t + len(P)])) % q

        return matches
