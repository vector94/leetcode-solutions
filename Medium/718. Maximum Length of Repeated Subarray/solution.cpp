class Solution {
public:
    int result = 0;
    int solve(int i, int j, vector<int> &nums1, vector<int> &nums2, vector<vector<int> > &dp){
        if (i == nums1.size() || j == nums2.size()){
            return 0;
        }
        int &ret = dp[i][j];
        if (ret != -1){
            return ret;
        }
        solve(i + 1, j, nums1, nums2, dp);
        solve(i, j + 1, nums1, nums2, dp);
        if (nums1[i] == nums2[j]){
            ret = solve(i + 1, j + 1, nums1, nums2, dp) + 1;
            result = max(result, ret);
            return ret;
        }
        return ret = 0;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        vector<vector<int> > dp(n1, vector<int> (n2, -1));
        
        solve(0, 0, nums1, nums2, dp);
        
        return result;
    }
};