class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        multiset<int> set1, set2;
        for (int x : nums){
            set2.insert(x);
        }
        int ret = 0;
        for (int i = 0; i < nums.size(); i++){
            set1.insert(nums[i]);
            set2.erase(set2.find(nums[i]));
            //cout << i << " " << set1.size() << " " << set2.size() << endl;
            if(*set1.rbegin() <= *set2.begin()){
                ret = i + 1;
                break;
            }
        }
        return ret;
    }
};