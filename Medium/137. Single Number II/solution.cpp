class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> MP;
        int ret;
        for (auto x : nums){
            MP[x]++;
        }
        for (auto x : nums){
            if (MP[x] == 1){
                ret = x;
            }
        }
        return ret;
    }
};