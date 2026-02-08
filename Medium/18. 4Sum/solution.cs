public class Solution {
    public IList<IList<int>> FourSum(int[] nums, int target) {
        IList<IList<int> > result = new List<IList<int> > ();
        
        if (nums.Length < 4)    return result;
        
        Array.Sort(nums);
        
        for (int i = 0; i < nums.Length; i++){
            if (i != 0 && nums[i] == nums[i - 1])   continue;
            for (int j = i + 1; j < nums.Length; j++){
                if (j != i + 1 && nums[j] == nums[j - 1])   continue;
                int need = target - (nums[i] + nums[j]);
                
                int left = j + 1;
                int right = nums.Length - 1;
                
                //Console.WriteLine(nums[i] + " " + nums[j] + " " + need);
                int start = left;
                while (left < right){
                    if (left != start && nums[left] == nums[left - 1]){
                        left++;
                        continue;
                    }
                    int sum = nums[left] + nums[right];
                    //Console.WriteLine(left + " " + right + " " + nums[left] + " " + nums[right] + " " + sum);
                    if (sum == need){
                        result.Add(new List<int> {nums[i], nums[j], nums[left], nums[right]});
                        if (nums[left] == nums[right]){
                            break;
                        }
                        left++;
                    }
                    else if (sum > need){
                        right--;
                    }
                    else{
                        left++;
                    }
                }
            }
        }
        
        return result;
    }
}