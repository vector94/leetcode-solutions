class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> count1, count2;

        for (int n : nums){
            count2[n]++;
        }

        for (int i = 0; i < nums.size(); i++){
            count2[nums[i]]--;
            count1[nums[i]]++;

            if (count1[nums[i]] * 2 > i + 1 && count2[nums[i]] * 2 > nums.size() - i - 1){
                return i;
            }
        }

        return -1;
    }
};