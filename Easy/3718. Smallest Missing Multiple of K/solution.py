class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        i = 1
        n = k
        while n in nums:
            i += 1
            n = k * i
        return n