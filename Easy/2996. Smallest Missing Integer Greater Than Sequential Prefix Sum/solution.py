class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        sum = nums[0]
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1] + 1:
                sum += nums[i]
            else:
                break

        i = sum
        while True:
            flag = False
            for j in range(len(nums)):
                if nums[j] == i:
                    flag = True
                    break
            if not flag:
                return i
            i += 1

        return 0