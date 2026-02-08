/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public bool LeafSimilar(TreeNode root1, TreeNode root2) {
        var leaves1 = new List<int>();
        var leaves2 = new List<int>();

        dfs(root1, ref leaves1);
        dfs(root2, ref leaves2);

        return Enumerable.SequenceEqual(leaves1, leaves2);
    }

    private void dfs(TreeNode root, ref List<int> leaves){
        if (root == null){
            return;
        }
        if (root.left == null && root.right == null){
            leaves.Add(root.val);
            return;
        }
        dfs(root.left, ref leaves);
        dfs(root.right, ref leaves);
    }
}