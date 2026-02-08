class Solution {
public:
    bool found = false;
    string ans;

    string findDifferentBinaryString(vector<string>& nums) {
        getDifferentString(0, "", nums);

        return ans;
    }

    void getDifferentString(int idx, string str, vector<string>& nums){
        if (found)  return;
        if (idx == nums.size()){
            if (find(nums.begin(), nums.end(), str) == nums.end()){
                found = true;
                ans = str;
            }
            return;
        }

        getDifferentString(idx + 1, str + '0', nums);
        getDifferentString(idx + 1, str + '1', nums);
    }
};