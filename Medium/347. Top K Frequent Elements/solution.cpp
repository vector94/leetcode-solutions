class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        
        int n = nums.size();
        vector<vector<int> > freqList(n + 1);
        unordered_map<int, bool> hashMap;
        
        for (int num : nums){
            count[num]++;
        }
        
        for (int num : nums){
            if (!hashMap[num]){
                hashMap[num] = true;
                freqList[count[num]].push_back(num);
            }
        }
        
        vector<int> result;
        for (int i = n; i >= 1; i--){
            if (!freqList[i].empty()){
                for (int num : freqList[i]){
                    result.push_back(num);
                    if (result.size() == k){
                        return result;
                    }
                }
            }
        }
        return result;
    }
};