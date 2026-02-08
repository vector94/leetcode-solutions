class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = accumulate(gas.begin(), gas.end(), 0);
        int costSum = accumulate(cost.begin(), cost.end(), 0);

        if (costSum > gasSum)   return -1;

        int total = 0;
        int result = 0;

        for (int i = 0; i < gas.size(); i++){
            total += gas[i] - cost[i];
            if (total < 0){
                total = 0;
                result = i + 1;
            }
        }

        return result;
    }
};