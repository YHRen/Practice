from typing import List
from bisect import bisect


class Solution:
    def check(self, mid):
        idx = bisect(self.v, mid-1)
        print(self.v, mid, idx)
        return self.n - idx + 1 > mid

    def hIndex(self, citations: List[int]) -> int:
        self.v = list(sorted(citations))
        self.n = len(self.v)
        lo, hi = 0, self.n+1
        ans = 0
        while lo < hi:
            mid = (hi+lo)//2
            if self.check(mid):
                ans = mid
                lo = mid+1
            else:
                hi = mid

        return ans

# sol = Solution()
# res = sol.hIndex([3,0,6,1,5])
# print(res)
# res = sol.hIndex([1])
# print(res)
# res = sol.hIndex([0])
# print(res)
