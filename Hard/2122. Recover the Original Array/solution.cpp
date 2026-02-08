class Solution {
public:
    
    int cnt[2005];
    unordered_map<int, int> myMap;
    int n;
    
    vector<int> recoverArray(vector<int>& nums) {
        vector<int> v;
        n = nums.size();
        
        int idx = 0;
        myMap[nums[0]] = idx++;
        
        for (int i = 1; i < nums.size(); i++){
            int diff = abs(nums[0] - nums[i]);
            if (diff % 2 == 0 && diff != 0){
                v.push_back(diff / 2);
            }
            
            if (myMap.find(nums[i]) == myMap.end()){
                myMap[nums[i]] = idx++;
            }
        }
        
        sort(nums.begin(), nums.end());
        int k = -1;
        
        for (int i = 0; i < v.size(); i++){
            memset(cnt, 0, sizeof(cnt));
            for (int j = 0; j < nums.size(); j++){
                cnt[myMap[nums[j]]]++;
            }
            
            bool ok = true;
            
            for (int j = 0; j < nums.size(); j++){
                if (cnt[myMap[nums[j]]] == 0){
                    continue;
                }
                if (myMap.find(nums[j] + 2 * v[i]) == myMap.end() ||  cnt[myMap[nums[j] + 2 * v[i]]] == 0){
                    ok = false;
                    break;
                }
                else{
                    cnt[myMap[nums[j]]]--;
                    cnt[myMap[nums[j] + 2 * v[i]]]--;
                }
            }
            
            if (ok){
                k = v[i];
                break;
            }
        }
        
        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; j < nums.size(); j++){
            cnt[myMap[nums[j]]]++;
        }
        
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++){
            if (cnt[myMap[nums[i]]] == 0){
                continue;
            }
            result.push_back(nums[i] + k);
            cnt[myMap[nums[i]]]--;
            cnt[myMap[nums[i] + 2 * k]]--;
        }  
        
        return result;
    }
};