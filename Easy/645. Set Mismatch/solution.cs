public class Solution {
    public int[] FindErrorNums(int[] nums) {
        var freq = new Dictionary<int, int>();
        
        foreach(int n in nums){
            if (!freq.ContainsKey(n))
                freq[n] = 1;
            else
                freq[n]++;
        }

        int missing = 0, duplicate = 0;
        for (int i = 1; i <= nums.Length; i++){
            if (freq.ContainsKey(i)){
                if (freq[i] == 2)
                    duplicate = i;
            }
            else{
                missing = i;
            }
        }

        int[] ans = {duplicate, missing};
        return ans;
    }
}