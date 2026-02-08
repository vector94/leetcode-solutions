class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evenSum = 0;
        for (int num : nums){
            if (num % 2 == 0)
                evenSum += num;
        }
        vector<int> result;
        for (int i = 0; i < queries.size(); i++){
            int prevNum = nums[queries[i][1]];
            nums[queries[i][1]] += queries[i][0];
            
            if (prevNum % 2 == 0){
                evenSum -= prevNum;
            }
            if (nums[queries[i][1]] % 2 == 0){
                evenSum += nums[queries[i][1]];
            }
            
            result.push_back(evenSum);
        }
        return result;
    }
};