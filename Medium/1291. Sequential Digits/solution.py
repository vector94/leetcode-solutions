class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        result = []
        num = 0

        self.backtrack(num, low, high, result)
        result.sort()

        return result

    def backtrack(self, num: int, low: int, high: int, result: List[int]) -> None:
        if num > high:
            return

        if low <= num and num <= high:
            result.append(num)

        if num == 0:
            for i in range(1, 10):
                self.backtrack(i, low, high, result)
        else:
            pre = num % 10
            if pre < 9:
                num = num * 10 + (pre + 1)
                self.backtrack(num, low, high, result)

        return