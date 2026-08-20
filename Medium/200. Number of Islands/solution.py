class Solution:

    def fill(self, x, y, grid) -> None:
        grid[x][y] = '0'

        dx = [1, 0, -1, 0]
        dy = [0, 1, 0, -1]

        for i in range(4):
            nx = dx[i] + x
            ny = dy[i] + y

            if nx >= 0 and nx < len(grid) and ny >= 0 and ny < len(grid[0]) and grid[nx][ny] == '1':
                self.fill(nx, ny, grid)

    def numIslands(self, grid: List[List[str]]) -> int:
        cnt = 0

        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == '1':
                    cnt += 1
                    self.fill(i, j, grid)

        return cnt