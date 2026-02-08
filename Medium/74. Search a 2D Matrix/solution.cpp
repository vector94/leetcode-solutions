class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int low = 0;
        int high = m - 1;
        
        int row = -1;
        
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] <= target && target <= matrix[mid][n - 1]){
                row = mid;
                break;
            }
            else if (matrix[mid][0] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        if (row == -1)  return false;
        
        low = 0;
        high = n - 1;
        
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (matrix[row][mid] == target){
                return true;
            }
            if (matrix[row][mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return false;
    }
};