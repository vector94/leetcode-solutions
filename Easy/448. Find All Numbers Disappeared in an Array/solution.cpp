class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        map<int, bool> myMap;
        for (int n : nums){
            myMap[n] = true;
        }

        vector<int> result;
        for (int i = 1; i <= nums.size(); i++){
            if (myMap.find(i) == myMap.end()){
                result.push_back(i);
            }
        }

        return result;
    }
};