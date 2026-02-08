public class Solution {
    public int[][] DivideArray(int[] nums, int k) {
        Array.Sort(nums);
        var myList = new List<int[]>();

        for (int i = 0; i < nums.Length; i += 3){
            var item = new[] { nums[i], nums[i + 1], nums[i + 2]};
            if (item[2] - item[0] > k)  return new int[0][];
            myList.Add(item);
        }

        return myList.ToArray();
    }
}