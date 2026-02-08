class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> count;
        for (int t : tasks){
            count[t]++;
        }
        int result = 0;
        for (int t : tasks){
            if (count[t] == 0)  continue;
            if (count[t] == 1){
                result = -1;
                break;
            }
            result += count[t] / 3 + (count[t] % 3 + 1) / 2;
            count[t] = 0;
        }
        return result;
    }
};