# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


from queue import Queue
class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        q = Queue()
        q.put((root, 0, 0))
        v = []
        while not q.empty():
            node, x, y = q.get()
            v.append((x, y, node.val))
            if node.left:
                q.put((node.left, x-1, y+1))
            if node.right:
                q.put((node.right, x+1, y+1))

        res = []
        v = sorted(v)
        for idx, (x, y, val) in enumerate(v):
            if idx == 0 or x > v[idx-1][0]:
                res.append([])
            res[-1].append(val)
        return res
