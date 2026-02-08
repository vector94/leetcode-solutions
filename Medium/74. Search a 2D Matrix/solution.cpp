class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int low = 0;
        int high = n - 1;
        
        while (low <= high){
            int mid = low + (high - low) / 2;
            
            if (matrix[mid][0] <= target && target <= matrix[mid][m - 1]){
                return binary_search(matrix[mid].begin(), matrix[mid].end(), target);
            }
            
            else if (target < matrix[mid][0]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return false;
    }
};