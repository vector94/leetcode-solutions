class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ret;
        for (int x : nums){
            ret.push_back(x * x);
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};