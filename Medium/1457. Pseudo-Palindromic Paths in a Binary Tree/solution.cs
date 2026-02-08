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
    public int PseudoPalindromicPaths (TreeNode root) {
        var freq = new Dictionary<int, int>();

        return DFS(root, freq);
    }

    private int DFS(TreeNode curNode, Dictionary<int, int> freq){
        if (freq.ContainsKey(curNode.val)){
            freq[curNode.val]++;
        }
        else{
            freq.Add(curNode.val, 1);
        }

        if (curNode.left == null && curNode.right == null){
            int retValue = 0;
            if (OddCount(freq) <= 1){
                retValue = 1;
            }
            freq[curNode.val]--;
            return retValue;
        }
        
        int result = 0;
        if (curNode.left != null){
            result += DFS(curNode.left, freq);
        }
        if (curNode.right != null){
            result += DFS(curNode.right, freq);
        }

        freq[curNode.val]--;
        return result;
    }

    private int OddCount(Dictionary<int, int> freq){
        int count = 0;
        Console.WriteLine("Starting here");
        foreach(var kvp in freq){
            Console.WriteLine(kvp.Key + " " + kvp.Value);
            if (kvp.Value % 2 != 0){
                count++;
            }
        }
        return count;
    }
}