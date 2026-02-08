class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n), maxRight(n);
        
        maxLeft[0] = maxRight[n - 1] = 0;
        
        for (int i = 1, j = n - 2; i < n; i++, j--){
            maxLeft[i] = max(maxLeft[i - 1], height[i - 1]);
            maxRight[j] = max(maxRight[j + 1], height[j + 1]);
        }
        
        int result = 0;
        
        for (int i = 1; i < n - 1; i++){
            result += max(0, min(maxLeft[i], maxRight[i]) - height[i]);
        }
        
        return result;
    }
};