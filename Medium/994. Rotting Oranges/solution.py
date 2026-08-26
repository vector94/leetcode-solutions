class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        myQueue = deque()

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 2:
                    myQueue.append((i, j, 0))

        ret = 0
        dx = [1, 0, -1, 0]
        dy = [0, 1, 0, -1]

        while myQueue:
            x, y, t = myQueue.popleft()
            print("here")
            ret = max(ret, t)

            print (f"x: {x}, y: {y}, t: {t}")

            for i in range(4):
                nx = dx[i] + x
                ny = dy[i] + y

                if nx >= 0 and nx < len(grid) and ny >= 0 and ny < len(grid[0]) and grid[nx][ny] == 1:
                    grid[nx][ny] = 2
                    myQueue.append((nx, ny, t + 1))


        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    return -1

        return ret

        