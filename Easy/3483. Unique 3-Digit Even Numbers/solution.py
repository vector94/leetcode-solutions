class Solution:
    def Set(self, num: int, pos: int) -> int:
        return num | (1 << pos)

    def Check(self, num: int, pos: int) -> bool:
        return (bool) (num & (1 << pos))
    
    def totalNumbers(self, digits: List[int]) -> int:
        mySet = set()
        self.solve(0, 0, 0, digits, mySet)
        return len(mySet)

    def solve(self, mask: int, cnt: int, num: int, digits: List[int], mySet: set) -> None:
        if cnt == 3:
            if num % 2 == 0:
                mySet.add(num)
            return

        for i in range(len(digits)):
            if not self.Check(mask, i):
                if cnt == 0 and digits[i] == 0:
                    continue

                self.solve(self.Set(mask, i), cnt + 1, num * 10 + digits[i], digits, mySet)
        