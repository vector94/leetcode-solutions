class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](vector<int> v1, vector<int> v2){
            return abs(v1[0] - v1[1]) > abs(v2[0] - v2[1]);
        });
        
        int cityA, cityB;
        cityA = cityB = costs.size() / 2;
        
        int result = 0;
        
        for (int i = 0; i < costs.size(); i++){
            if (costs[i][0] < costs[i][1]){
                if (cityA){
                    result += costs[i][0];
                    cityA--;
                }
                else{
                    result += costs[i][1];
                    cityB--;
                }
            }
            else{
                if (cityB){
                    result += costs[i][1];
                    cityB--;
                }
                else{
                    result += costs[i][0];
                    cityA--;
                }
            }
        }
        
        return result;
    }
};