class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> seen;
        seen[0] = -1;
        
        int best = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0)   cnt++;
            else                cnt--;
            
            if (seen.find(cnt) != seen.end()){
                best = max(best, i - seen[cnt]);
            }
            else{
                seen[cnt] = i;
            }
        }
        
        return best;
    }
};