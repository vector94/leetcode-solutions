class Solution:
    def closedIsland(self, grid: list[list[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])

        for i in range(rows):
            if grid[i][0] == 0:
                self.dfs(i, 0, grid)
            if grid[i][cols - 1] == 0:
                self.dfs(i, cols - 1, grid)

        for j in range(cols):
            if grid[0][j] == 0:
                self.dfs(0, j, grid)
            if grid[rows - 1][j] == 0:
                self.dfs(rows - 1, j, grid)

        ans = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 0:
                    self.dfs(i, j, grid)
                    ans += 1

        return ans


    def dfs(self, r: int, c: int, grid: list[list[int]]) -> None:
        grid[r][c] = 1

        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]

        for i in range(4):
            nx = dx[i] + r
            ny = dy[i] + c

            if nx >= 0 and nx < len(grid) and ny >= 0 and ny < len(grid[0]) and grid[nx][ny] == 0:
                self.dfs(nx, ny, grid)