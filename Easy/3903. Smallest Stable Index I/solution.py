class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        maxNums = [0] * len(nums)
        minNums = [1e9] * len(nums)

        i = 1
        j = len(nums) - 2
        maxNums[0] = nums[0]
        minNums[len(nums) - 1] = nums[len(nums) - 1]

        while i < len(nums):
            maxNums[i] = max(maxNums[i - 1], nums[i])
            minNums[j] = min(minNums[j + 1], nums[j])
            i += 1
            j -= 1

        for i in range(len(nums)):
            if maxNums[i] - minNums[i] <= k:
                return i

        return -1


        