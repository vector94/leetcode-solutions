class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> myMap;

        for (int n : nums){
            int rem;
            if (n < 0){
                rem = ((n % value) + value) % value;
            }
            else{
                rem = n % value;
            }

            myMap[rem]++;
        }

        for (int i = 0; i <= nums.size(); i++){
            if (myMap[i % value] == 0){
                return i;
            }

            myMap[i % value]--;
        }

        return nums.size();
    }
};