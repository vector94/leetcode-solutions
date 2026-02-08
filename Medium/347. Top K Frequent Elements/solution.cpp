class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for(int n : nums){
            hashMap[n]++;
        }

        vector<vector<int> > freqList(nums.size() + 1);
        for (auto it : hashMap){
            freqList[it.second].push_back(it.first);
        }

        vector<int> result;
        for (int i = nums.size(); i >= 1; i--){
            for (int j : freqList[i]){
                result.push_back(j);
                if (result.size() == k) return result;
            }
        }

        return result;
    }
};