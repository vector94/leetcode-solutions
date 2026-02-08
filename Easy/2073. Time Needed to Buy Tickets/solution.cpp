class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        for (int i = 0; i < tickets.size(); i++){
            if (i <= k){
                ans += tickets[i] <= tickets[k] ? tickets[i] : tickets[k];
            }
            else{
                ans += tickets[i] >= tickets[k] ? tickets[k] - 1 : tickets[i];
            }
        }
        return ans;
    }
};