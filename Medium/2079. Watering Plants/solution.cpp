class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int result = 0;
        int total = capacity;
        int pos = -1;
        
        for (int i = 0; i < plants.size(); i++){
            if (plants[i] <= total){
                total -= plants[i];
                result += i - pos;
                pos = i;
            }
            else{
                total = capacity;
                result += pos + i + 2;
                pos = i;
                total -= plants[i];
            }
        }
        
        return result;
    }
};