# Definition for a binary tree node.


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


from queue import Queue
class Solution:
    def pathSum(self, root: TreeNode, target: int) -> int:
        q = Queue()
        if root is None:
            return 0

        res = 0
        q.put((root, {0: 1}))
        while not q.empty():
            node, dic = q.get()
            val = node.val
            if target - val in dic.keys():
                res += dic[target-val]
            if node.left:
                tmp = {val+k: v for k, v in dic.items()}
                if 0 not in tmp.keys():
                    tmp[0] = 1
                else:
                    tmp[0] += 1
                q.put((node.left, tmp))
            if node.right:
                tmp = {node.val+k: v for k, v in dic.items()}
                if 0 not in tmp.keys():
                    tmp[0] = 1
                else:
                    tmp[0] += 1
                q.put((node.right, tmp))

        return res
