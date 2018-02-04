class Solution:
    def isIdealPermutation(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        def find_local(A):
            cnt = 0;
            for i,j in zip(A[:],A[1:]):
                if j < i:
                    cnt += 1
            return cnt
        
        def find_global(A):
            cnt = 0;
            l = []
            for i in A:
                x = bisect.bisect_right(l, i)
                cnt += len(l) - x
                bisect.insort(l, i)
            return cnt
        
        print(find_local(A))
        print(find_global(A))
        return find_local(A) == find_global(A)
        
