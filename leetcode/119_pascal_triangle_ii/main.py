from typing import List
class Solution:
    def getRow(self, k: int) -> List[int]:
        if k == 0:
            return [1]
        if k == 1:
            return [1, 1]
        u, v = [1]*(k+1), [1]*(k+1)
        for row in range(1,k+1):
            for j in range(1, row):
                v[j] = u[j]+u[j-1]
            u = v.copy()
        return v

sol  = Solution()
print( sol.getRow(3) )
