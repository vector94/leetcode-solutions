class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ret = 0;
        for (int x : nums){
            string num = to_string(x);
            if (num.size() % 2 == 0){
                ret++;
            }
        }
        return ret;
    }
};