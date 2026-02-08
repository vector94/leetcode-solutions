class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        int result;
        
        while (low <= high){
            int mid = low + (high - low) / 2;
            
            if (countLessOrEqual(matrix, mid) >= k){
                result = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return result;
    }
    
    int countLessOrEqual(vector<vector<int>>& matrix, int num){
        int cnt = 0;
        for (int i = 0; i < matrix.size(); i++){
            int pos = upper_bound(matrix[i].begin(), matrix[i].end(), num) - matrix[i].begin();
            cnt += pos;
        }
        return cnt;
    }
};