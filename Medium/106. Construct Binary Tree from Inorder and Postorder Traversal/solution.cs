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
    
    //private Dictionary<int, int> hashMap;
    
    public TreeNode BuildTreeHelper(ref int[] inorder, ref int[] postorder, 
                                    ref Dictionary <int, int> inorderIndex, int left, int right, ref int index){
        
        
        if (left > right)   return null;
        
        
        TreeNode currentNode = new TreeNode(postorder[index]);
        int currentIndex = inorderIndex[postorder[index]];
        
        index--;
        
        //if (left == right)  return currentNode;
        
        
        //Console.WriteLine(index + " " + left + " " + right + " " + currentIndex);
        
        currentNode.right = BuildTreeHelper(ref inorder, ref postorder, ref inorderIndex, currentIndex + 1, right, ref index);
        currentNode.left = BuildTreeHelper(ref inorder, ref postorder, ref inorderIndex, left, currentIndex - 1, ref index);
        
        return currentNode;
    }
    
    public TreeNode BuildTree(int[] inorder, int[] postorder) {
        Dictionary <int, int> inorderIndex = new Dictionary<int, int> ();
        
        int length = inorder.Length;
        
        for (int i = 0; i < length; i++){
            inorderIndex[inorder[i]] = i;
        }
        
        int index = length - 1;
        
        return BuildTreeHelper(ref inorder, ref postorder, ref inorderIndex, 0, length - 1, ref index);
    }
}