class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        total = n * 2
        reservedSeats.sort()
        checks = [
            [2, 3, 4, 5],
            [6, 7, 8, 9],
            [4, 5, 6, 7]
        ]

        i = 0
        while i < len(reservedSeats):
            curRow = reservedSeats[i][0]
            seats = []
            while i < len(reservedSeats) and reservedSeats[i][0] == curRow:
                seats.append(reservedSeats[i][1])
                i += 1
            i -= 1

            total -= 2
            cnt = 0
            for j in range(2):
                flag = True
                for k in range(4):
                    if checks[j][k] in seats:
                        flag = False
                        break
                if flag:
                    cnt += 1
            if cnt != 0:
                total += cnt
            else:
                flag = True
                for j in range(4):
                    if checks[2][j] in seats:
                        flag = False
                        break
                if flag:
                    total += 1
            
            i += 1
        
        return total