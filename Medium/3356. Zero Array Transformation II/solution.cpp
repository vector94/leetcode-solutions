class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        if (!check(queries.size() - 1, nums, queries)){
            return -1;
        }

        bool allZero = true;
        for (int n : nums){
            if (n > 0)  allZero = false;
        }

        if (allZero)    return 0;

        int left = 0;
        int right = queries.size() - 1;
        int ans;

        while (left <= right){
            int mid = (left + right) / 2;
            if (check(mid, nums, queries)){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return ans + 1;
    }

    bool check(int k, vector<int>& nums, vector<vector<int>>& queries){
        int N = nums.size();
        vector<int> differenceArray(N + 1);
        
        for (int i = 0; i <= k; i++){
            int left = queries[i][0];
            int right = queries[i][1];
            int val = queries[i][2];

            differenceArray[left] += val;
            differenceArray[right + 1] -= val; 
        }

        int sum = 0;
        for (int i = 0; i < N; i++){
            sum += differenceArray[i];
            if (sum < nums[i])  return false;
        }

        return true;
    }
};