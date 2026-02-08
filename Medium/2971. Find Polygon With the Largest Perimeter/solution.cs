public class Solution {
    public long LargestPerimeter(int[] nums) {
        long result = -1;
        long sum = 0;
        Array.Sort(nums);
        for (int i = 0; i < nums.Length; i++){
            sum += nums[i];
            
            if (i > 1){
                if (sum - nums[i] > nums[i]){
                    result = sum;
                }
            }
        }
        return result;
    }
}