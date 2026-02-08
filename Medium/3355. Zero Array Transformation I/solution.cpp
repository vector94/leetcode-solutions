class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size();
        vector<int> diffList(N + 1, 0);

        for (int i = 0; i < queries.size(); i++){
            diffList[queries[i][0]]--;
            diffList[queries[i][1] + 1]++;
        }

        for (int i = 1; i < N; i++){
            diffList[i] += diffList[i - 1];
        }

        for (int i = 0; i < N; i++){
            nums[i] += diffList[i];
            if (nums[i] > 0)    return false;
        }

        return true;
    }
};