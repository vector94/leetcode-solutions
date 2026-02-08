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
    
    public void InorderTraversalHelper(TreeNode root, ref List<int> result){
        if (root == null)   return;
        InorderTraversalHelper(root.left, ref result);
        //Console.Write(root.val + " ");
        result.Add(root.val);
        InorderTraversalHelper(root.right, ref result);
    }
    
    public IList<int> InorderTraversal(TreeNode root) {
        List<int> result = new List<int> ();
        
        InorderTraversalHelper(root, ref result);
        
        return result;
    }
}