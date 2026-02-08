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
    public IList<int> PreorderTraversal(TreeNode root) {
        List<int> result = new List<int> ();
        
        Stack <TreeNode> myStack = new Stack<TreeNode> ();
        TreeNode currentNode = root;
        
        while (myStack.Count > 0 || currentNode != null){
            if (currentNode != null){
                result.Add(currentNode.val);
                myStack.Push(currentNode);
                currentNode = currentNode.left;
            }
            else{
                currentNode = myStack.Pop();
                currentNode = currentNode.right;
            }
        }
        
        return result;
    }
}