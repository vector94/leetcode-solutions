class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i++){
            for (int j = i + 1; j < nums.size(); j++){
                hashMap[nums[i] * nums[j]]++;
            }
        }
        int ans = 0;
        for (auto it : hashMap){
            ans += (it.second * (it.second - 1)) / 2 * 8;
        }

        return ans;
    }
};