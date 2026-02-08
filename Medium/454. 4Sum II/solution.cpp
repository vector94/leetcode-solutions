class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> hashMap;
        for (int x : nums1){
            for (int y : nums2){
                hashMap[x + y]++;
            }
        }
        int result = 0;
        for (int x : nums3){
            for (int y : nums4){
                result += hashMap[-(x + y)];
            }
        }
        return result;
    }
};