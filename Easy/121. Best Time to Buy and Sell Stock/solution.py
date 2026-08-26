class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ret = 0
        minStock = prices[0]

        for p in prices:
            ret = max(ret, p - minStock)
            minStock = min(minStock, p)

        return ret