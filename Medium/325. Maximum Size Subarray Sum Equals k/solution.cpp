class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        map<long, int> hashMap;
        vector<long> prefixSum;
        prefixSum.push_back(0);
        hashMap[0] = 0;

        int result = 0;

        for (int i = 0; i < nums.size(); i++){
            long curSum = prefixSum.back() + nums[i];
            if (hashMap.find(curSum - k) != hashMap.end()){
                result = max(result, i - hashMap[curSum - k] + 1);
            }
            if (hashMap.find(curSum) == hashMap.end()){
                hashMap[curSum] = i + 1;
            }
            prefixSum.push_back(curSum);
        }

        return result;
    }
};

/*
prefix[x] - prefix[y] = k


*/