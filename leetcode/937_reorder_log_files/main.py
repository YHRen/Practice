class Solution:
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        v = []
        u = []
        for x in logs:
            a, *b = x.split()
            if b[0].isdigit():
                u.append(x)
            else:
                v.append( b+[a] )
        vs = sorted(v)
        vs = [ ' '.join([x[-1]] + x[:-1]) for x in vs]
        ans = vs + u;

        return ans

sol = Solution()
print(sol.reorderLogFiles(["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]))


                
	
