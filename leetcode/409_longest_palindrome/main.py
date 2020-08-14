from collections import Counter
class Solution:
    def longestPalindrome(self, s: str) -> int:
        cnt = Counter()
        for c in s:
            cnt[c] += 1
        ans = 0
        has_odd = 0
        for v in cnt.values():
            if v%2 == 0:
                ans += v
            else:
                ans += v-1
                has_odd = 1

        ans += has_odd
        return ans
