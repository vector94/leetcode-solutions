class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        freq = defaultdict(int)
        
        l = r = 0
        res = 0

        while r < len(s):
            print(f"l : {l}, r {r}, freq[s[r]]: {freq[s[r]]}")
            if freq[s[r]] < 2:
                freq[s[r]] += 1
                r += 1
                res = max(res, r - l)
                continue

            while freq[s[r]] == 2:
                freq[s[l]] -= 1
                l += 1

        return res 

        return 0