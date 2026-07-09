class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n);
        int comp = 1;
        component[0] = 1;
        for (int i = 1; i < n; i++){
            if (abs(nums[i] - nums[i - 1]) > maxDiff){
                comp++;
            }

            component[i] = comp;
        }

        vector<bool> results;
        for (int i = 0; i < queries.size(); i++){
            if (component[queries[i][0]] == component[queries[i][1]]){
                results.push_back(true);
            }
            else{
                results.push_back(false);
            }
        }

        return results;
    }
};