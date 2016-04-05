
class KnuthMorrisPratt:

    @staticmethod
    def calculate_prefix_function(pattern):
        """
        Prefix function is a table containing information about how many characters have been matched in a given
        state.
        """

        prefix = [0, ]          # Prefix table
        k = 0                   # Number of matched characters

        for i in range(1, len(pattern)):
            if pattern[i] == pattern[k]:
                k += 1
            else:
                while k > 0 & prefix[k] != pattern[i]:
                    k = prefix[k]
            prefix.append(k)
        return prefix

    @staticmethod
    def match(pattern, text):
        """
        Knuth-Morris-Pratt pattern matcher.
        """

        if len(text) < len(pattern):
            return []

        π = KnuthMorrisPratt.calculate_prefix_function(pattern)
        results = []            # Indexes of matched patterns
        q = 0                   # The number of characters that we have already matched

        for s in range(0, len(text)):
            while (q > 0) & (text[s] != pattern[q]):
                q = π[q]
            if text[s] == pattern[q]:
                q += 1
            if q == len(pattern):
                results.append(s-len(pattern) + 1)
                q = π[q-1]  # If this runs q has already been incremented above
        return results
