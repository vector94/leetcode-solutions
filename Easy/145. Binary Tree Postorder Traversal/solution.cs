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
    public IList<int> PostorderTraversal(TreeNode root) {
        List<int> result = new List<int> ();
        
        Stack<TreeNode> myStack = new Stack<TreeNode> ();
        TreeNode currentNode = root;
        
        while (myStack.Count > 0 || currentNode != null){
            if (currentNode != null){
                myStack.Push(currentNode);
                currentNode = currentNode.left;
            }
            
            else{
                TreeNode temp = myStack.Peek().right;
                if (temp == null){
                    temp = myStack.Pop();
                    result.Add(temp.val);
                    while (myStack.Count > 0 && myStack.Peek().right == temp){
                        temp = myStack.Pop();
                        result.Add(temp.val);
                    }
                }
                else{
                    currentNode = temp;
                }
            }
        }
        
        return result;
    }
}