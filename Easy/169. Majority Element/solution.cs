public class Solution {
    public int MajorityElement(int[] nums) {
        int major = nums[0];
        int count = 1;
        for (int i = 1; i < nums.Length; i++){
            if (nums[i] == major){
                count++;
            }
            else if (count == 0){
                major = nums[i];
                count++;
            }
            else{
                count--;
            }
        }
        
        return major;
    }
}