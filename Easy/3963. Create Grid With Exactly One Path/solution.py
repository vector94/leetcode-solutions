class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        result = []
        for i in range(m):
            path = ""
            for j in range(n):
                if i == 0 or j == n - 1:
                    path += "."
                else:
                    path += "#"
            result.append(path)
    
        return result
        