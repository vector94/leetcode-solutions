class Solution:
    def checkDivisibility(self, n: int) -> bool:
        sum = 0
        prod = 1

        num = n
        while num:
            sum += num % 10
            prod *= num % 10

            num //= 10

        return n % (sum + prod) == 0
        