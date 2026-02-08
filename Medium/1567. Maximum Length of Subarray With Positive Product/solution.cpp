class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int result = 0;
        int left = -1;
        int firstNegIdx = -1, lastNegIdx;
        int negCount = 0;
        
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                
                if (left != -1){
                    if (negCount % 2 == 0){
                        result = max(result, i - left);
                    }
                    else{
                        result = max({result, i - firstNegIdx - 1, lastNegIdx - left});
                    }
                }
                
                left = -1;
                firstNegIdx = -1;
                negCount = 0;
                continue;
            }
            
            if (left == -1){
                left = i;
            }
            
            if (nums[i] < 0){
                if (firstNegIdx == -1){
                    firstNegIdx = i;
                }
                lastNegIdx = i;
                negCount++;
            }
            
        }
        
        if (left != -1){
            if (negCount % 2 == 0){
                result = max(result, (int)nums.size() - left);
            }
            else{
                result = max({result, (int)nums.size() - firstNegIdx - 1, lastNegIdx - left});
            }
        }
        
        return result;
    }
};