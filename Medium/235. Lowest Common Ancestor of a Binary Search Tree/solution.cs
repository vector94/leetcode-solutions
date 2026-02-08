/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */

public class Solution {
    
    public TreeNode LowestCommonAncestorHelper(TreeNode currentNode, int p, int q){
        if (p < currentNode.val && q < currentNode.val){
            return LowestCommonAncestorHelper(currentNode.left, p, q);
        }
        else if (p > currentNode.val && q > currentNode.val){
            return LowestCommonAncestorHelper(currentNode.right, p, q);
        }
        return currentNode;
    }
    
    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        return LowestCommonAncestorHelper(root, p.val, q.val);
    }
}