class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);
        
        if (totalGas < totalCost)   return -1;
        
        int start = 0;
        int total = 0;
        
        for (int i = 0; i < gas.size(); i++){
            total += gas[i] - cost[i];
            if (total < 0){
                start = i + 1;
                total = 0;
            }
        }
        
        return start;
    }
};