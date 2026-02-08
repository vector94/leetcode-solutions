public class Solution {
    public int[] RearrangeArray(int[] nums) {
        int positiveIndex = 0;
        int negetiveIndex = 0;
        int flag = 1;
        
        int i = 0;
        int[] result = new int[nums.Length];
        
        while (i < nums.Length){
            if (flag == 1){
                while (nums[positiveIndex] < 0){
                    positiveIndex++;
                }
                result[i++] = nums[positiveIndex++];
            }
            else{
                while (nums[negetiveIndex] > 0){
                    negetiveIndex++;
                }
                result[i++] = nums[negetiveIndex++];
            }
            flag ^= 1;
        }
        
        return result;
    }
}