class Solution:
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        d = collections.Counter(S);
        ans = 0;
        for c in J:
            ans += d.get(c,0);
        return ans;
        
