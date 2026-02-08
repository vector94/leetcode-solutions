class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> vec1, vec2, vec3;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] < pivot)    vec1.push_back(nums[i]);
            else if (nums[i] > pivot)   vec3.push_back(nums[i]);
            else    vec2.push_back(nums[i]);
        }

        vector<int> result;
        result.insert(result.end(), vec1.begin(), vec1.end());
        result.insert(result.end(), vec2.begin(), vec2.end());
        result.insert(result.end(), vec3.begin(), vec3.end());

        return result;
    }
};