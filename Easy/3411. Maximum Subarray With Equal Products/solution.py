class Solution:    
    def maxLength(self, nums: List[int]) -> int:
        result = 0
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                curProd = math.prod(nums[i: j + 1])
                curGcd = math.gcd(*nums[i: j + 1])
                curLcm = math.lcm(*nums[i: j + 1])

                if curProd == curLcm * curGcd:
                    result = max(result, (j - i) + 1)

        return result
        