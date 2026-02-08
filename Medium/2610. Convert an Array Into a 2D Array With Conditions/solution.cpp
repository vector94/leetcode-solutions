class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> result;
        map<int, int> count;

        for (int x : nums){
            count[x]++;
        }
        int total = nums.size();
        while (total > 0){
            vector<int> newRow;
            for (int i = 1; i <= nums.size(); i++){
                if (count[i] > 0){
                    count[i]--;
                    total--;
                    newRow.push_back(i);
                }
            }
            result.push_back(newRow);
        }
        return result;
    }
};