class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        int sz = nums.size();
        if (sz == 1)    return 0;
        
        int et, ot;
        et = ot = 0;
        
        unordered_map<int, int> even;
        unordered_map<int, int> odd;
        
        for (int i = 0; i < nums.size(); i++){
            if (i % 2 == 0){
                even[nums[i]]++;
                et++;
            }
            else {
                odd[nums[i]]++;
                ot++;
            }       
        }
        
        vector<pair<int, int>> e, o;
        for (auto it : even){
            e.push_back({it.first, it.second});
        }
        for (auto it : odd){
            o.push_back({it.first, it.second});
        }
        
        sort(e.begin(), e.end(), [](pair<int, int> a, pair<int, int> b){
           return a.second > b.second;
        });
        sort(o.begin(), o.end(), [](pair<int, int> a, pair<int, int> b){
           return a.second > b.second;
        });
        
        if (e[0].first == o[0].first){
            int r1, r2;
            if (o.size() == 1){
                r1 = et - e[0].second + ot;
            }
            else{
                r1 = et - e[0].second + ot - o[1].second;
            }
            
            if (e.size() == 1){
                r2 = et + ot - o[0].second;
            }
            else{
                r2 = et - e[1].second + ot - o[0].second;
            }
            return min(r1, r2);
        }
        else{
            return et - e[0].second + ot - o[0].second;
        }
        
    }
};