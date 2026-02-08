class Solution {
public:
    
    bool check(vector<int> &piles, int h, int k){
        int total = 0;
        for (int b : piles){
            total += (b + k - 1) / k;
        }
        return (total <= h);
    }
    
    int result;
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        while (left <= right){
            int mid = left + (right - left) / 2;
            
            if (check(piles, h, mid)){
                result = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        
        return result;
    }
};