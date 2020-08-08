from typing import List

class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        v = list(map(lambda x: x-1, nums))
        print(v)
        res = []
        for i in range(len(v)):
            if i == v[i]:
                continue
            while i != v[i] and v[i] != -1:
                if v[i] != v[v[i]]:
                    b = v[i]
                    c = v[v[i]]
                    v[b] = v[i]
                    v[i] = c
                else:
                    res.append(v[i])
                    v[i] = -1

        return list(map(lambda x: x+1, res))
