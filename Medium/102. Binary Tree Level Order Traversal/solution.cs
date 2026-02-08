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
    public IList<IList<int>> LevelOrder(TreeNode root) {
        
        List<IList<int> > result = new List<IList<int> >();
        
        if (root == null)   return result;
        
        Queue<TreeNode> myQueue = new Queue<TreeNode> ();
        myQueue.Enqueue(root);
        
        while (myQueue.Count > 0){
            int levelSize = myQueue.Count;
            List<int> currentList = new List<int> ();
            
            for (int i = 0; i < levelSize; i++){
                
                TreeNode currentNode = myQueue.Dequeue();
                currentList.Add(currentNode.val);
                
                if (currentNode.left != null){
                    myQueue.Enqueue(currentNode.left);
                }
                if (currentNode.right != null){
                    myQueue.Enqueue(currentNode.right);
                }
            }
            
            result.Add(currentList);
        }
        
        return result;
    }
}