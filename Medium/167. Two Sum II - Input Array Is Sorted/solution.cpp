class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        for (int i = 0; i < numbers.size(); i++){
            int x = numbers[i];
            int y = target - x;
            int idx = lower_bound(numbers.begin() + i + 1, numbers.end(), y) - numbers.begin();
            if (idx == numbers.size() || numbers[idx] != y){
                continue;
            }
            ret.push_back(i + 1);
            ret.push_back(idx + 1);
            break;
        }
        return ret;
    }
};