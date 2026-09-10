# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        triplet = (0, 0, 0)
        return self.solve(root, triplet)[0]

    def solve(self, node: TreeNode, triplet: (int, int, int)) -> (int, int, int):
        if node == None:
            return [0, 0, 0]

        left = self.solve(node.left, triplet)
        right = self.solve(node. right, triplet)

        curTriplet = (left[0] + right[0], left[1] + right[1] + node.val, left[2] + right[2] + 1)
        if curTriplet[1] // curTriplet[2] == node.val:
            curTriplet = (curTriplet[0] + 1, curTriplet[1], curTriplet[2])

        return curTriplet