class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int max1, max2, max3;
        bool f1, f2, f3;
        f1 = f2 = f3 = false;
        for (int i = 0; i < nums.size(); i++){
            if (f1 && f2 && f3){
                if (nums[i] == max1 || nums[i] == max2 || nums[i] == max3){
                    continue;
                }
                if (nums[i] > max1){
                    max3 = max2;
                    max2 = max1;
                    max1 = nums[i];
                }
                else if (nums[i] > max2){
                    max3 = max2;
                    max2 = nums[i];
                }
                else if (nums[i] > max3){
                    max3 = nums[i];
                }
            }
            else if (f1 && f2){
                if (nums[i] == max1 || nums[i] == max2){
                    continue;
                }
                if (nums[i] > max1){
                    max3 = max2;
                    max2 = max1;
                    max1 = nums[i];
                }
                else if (nums[i] > max2){
                    max3 = max2;
                    max2 = nums[i];
                }
                else{
                    max3 = nums[i];
                }
                f3 = true;
            }
            else if (f1){
                if (nums[i] == max1){
                    continue;
                }
                if (nums[i] > max1){
                    max2 = max1;
                    max1 = nums[i];
                }
                else{
                    max2 = nums[i];
                }
                f2 = true;
            }
            else{
                max1 = nums[i];
                f1 = true;
            }
        }
        if (!f3){
            return max1;
        }
        return max3;
    }
};