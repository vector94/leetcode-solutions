class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        N = len(arr)

        myVec = []
        for i in range(N):
            myVec.append([arr[i], i])

        myVec.sort()

        result = [0] * N
        rank = 1

        for i in range(N):
            if i > 0 and myVec[i][0] != myVec[i - 1][0]:
                rank += 1

            result[myVec[i][1]] = rank

        return result