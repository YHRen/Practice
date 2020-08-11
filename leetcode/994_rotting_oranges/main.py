from queue import Queue
from typing import List


class Solution:

    def in_range(self, i, j):
        return i < self.n and i >= 0 and j < self.m and j >= 0

    def init_queue(self, grid):
        q = Queue()
        for i in range(self.n):
            for j in range(self.m):
                if grid[i][j] == 2:
                    q.put((i, j))
        return q

    def orangesRotting(self, grid: List[List[int]]) -> int:
        self.n, self.m = len(grid), len(grid[0])
        q = self.init_queue(grid)
        res = 0

        while not q.empty():
            p = Queue()
            while not q.empty():
                x, y = q.get()
                for di, dj in zip([0, 1, 0, -1], [1, 0, -1, 0]):
                    if self.in_range(x+di, y+dj) and grid[x+di][y+dj] == 1:
                        grid[x+di][y+dj] = 2
                        p.put((x+di, y+dj))

            if not p.empty():
                res += 1
                q = p
            print(grid)

        for row in grid:
            for x in row:
                if x == 1:
                    return -1

        return res
