class Solution:
    def count_unguarded(
        self, m: int, n: int, guards: list[list[int]], walls: list[list[int]]
    ) -> int:
        grid = [[0] * n for _ in range(m)]

        for row, col in guards:
            grid[row][col] = 1

        for row, col in walls:
            grid[row][col] = 1

        for row, col in guards:
            for i in range(row - 1, -1, -1):
                if grid[i][col] == 1:
                    break
                grid[i][col] = 2

            for i in range(row + 1, m):
                if grid[i][col] == 1:
                    break
                grid[i][col] = 2

            for j in range(col - 1, -1, -1):
                if grid[row][j] == 1:
                    break
                grid[row][j] = 2

            for j in range(col + 1, n):
                if grid[row][j] == 1:
                    break
                grid[row][j] = 2

        return sum(col == 0 for row in grid for col in row)
