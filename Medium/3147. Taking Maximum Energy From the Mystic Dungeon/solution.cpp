class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = INT_MIN;
        
        vector<int> energySum(k, 0);

        for (int i = energy.size() - 1; i >= 0; i--){
            energySum[i % k] += energy[i];
            ans = max(ans, energySum[i % k]);
        }

        return ans;
    }
};