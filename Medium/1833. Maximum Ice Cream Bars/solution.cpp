class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int result = 0;
        for (int cost : costs){
            if (cost <= coins){
                coins -= cost;
                result++;
            }
            else{
                break;
            }
        }
        return result;
    }
};