class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        int i = 0;
        for (int j = 0; j < nums.size(); j++){
            if (hashMap[nums[j]] < 2){
                hashMap[nums[j]]++;
                swap(nums[i++], nums[j]);
            }
        }
        return i;
    }
};