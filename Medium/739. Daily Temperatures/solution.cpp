class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> result(temperatures.size(), 0);
        stack<int> ST;
        
        for (int i = 0; i < temperatures.size(); i++){
            
            while (!ST.empty() && temperatures[i] > temperatures[ST.top()]){
                int day = ST.top();
                ST.pop();
                result[day] = i - day;
            }
            
            ST.push(i);
        }
        
        return result;
    }
};