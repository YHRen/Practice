class Solution:
    def titleToNumber(self, s: str) -> int:
        res, base = 0, 26
        pw = 1
        for c in s[::-1]:
            res += (ord(c)-ord('A')+1)*pw
            pw *= base
        return res
