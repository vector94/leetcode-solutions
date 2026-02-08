class Solution {
public:
    
    int check(int num, int m, int n){
        
        int total = 0;
        for (int i = 1; i <= m; i++){
            total += min(n, num / i);
        }
        
        return total; 
    }
    
    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m * n;
        
        int result;
        
        while (low <= high){
            int mid = low + (high - low) / 2;
            
            if (check(mid, m, n) >= k){
                result = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return result;
    }
};