class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        int cnt = 0;
        for (int i = 0; i < nums.size() && cnt < nums.size(); i++){
            int pre_val = nums[i];
            int cur = i;
            while (true){
                int nxt = cur + k;
                if (nxt >= nums.size()){
                    nxt %= nums.size();
                }
                int cur_val = nums[nxt];
                nums[nxt] = pre_val;
                pre_val = cur_val;
                cur = nxt;
                cnt++;
                if (cur == i){
                    break;
                }
            }
        }
    }
};