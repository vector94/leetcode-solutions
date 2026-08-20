class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        if k == len(nums):
            return max(nums)

        freq = defaultdict(int)

        for n in nums:
            freq[n] += 1

        ret = -1
        if k == 1:
            for n in nums:
                if freq[n] == 1:
                    ret = max(ret, n)
            return ret

        if freq[nums[0]] == 1:
            ret = nums[0]
        if freq[nums[len(nums) - 1]] == 1:
            ret = max(ret, nums[len(nums) - 1])

        return ret
        