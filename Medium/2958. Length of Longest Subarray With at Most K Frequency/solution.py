class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        freq = defaultdict(int)

        l = r = 0
        ans = 0
        
        while l <= r and r < len(nums):
            if freq[nums[r]] < k:
                freq[nums[r]] += 1
                ans = max(ans, r - l + 1)
                r += 1
            else:
                while freq[nums[r]] == k:
                    freq[nums[l]] -= 1
                    l += 1

        return ans
        