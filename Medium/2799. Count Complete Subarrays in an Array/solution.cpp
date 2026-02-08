class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> mySet;
        for (int n : nums){
            mySet.insert(n);
        }

        int distinctCount = mySet.size();
        
        unordered_map<int, int> hashMap;
        int curDistCount = 0;

        int N = nums.size();
        int left, right;
        left = right = 0;
        int ans = 0;

        while (left <= right){
            if (curDistCount == distinctCount){
                cout << left << " " << right << endl;
                ans += (N - right) + 1;
                hashMap[nums[left]]--;
                if (hashMap[nums[left]] == 0){
                    curDistCount--;
                }
                left++;
            }
            else{
                if (right == N) break;
                if (hashMap[nums[right]] == 0){
                    curDistCount++;
                }
                
                hashMap[nums[right]]++;
                right++;
            }
        }

        return ans;
    }
};