from typing import List
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        v = sorted(intervals, key=lambda x: x[1])
        n = len(v)
        if n <= 1:
            return 0
        prv = v[0][1]
        res = 0
        for x in v[1::]:
            if x[0] < prv:
                res += 1
            else:
                prv = x[1]

        return res
