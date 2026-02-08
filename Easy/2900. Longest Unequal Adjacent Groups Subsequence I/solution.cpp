class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ret1, ret2;

        int flag1 = 0;
        int flag2 = 1;

        for (int i = 0; i < words.size(); i++){
            if (groups[i] == flag1){
                ret1.push_back(words[i]);
                flag1 ^= 1;
            }

            if (groups[i] == flag2){
                ret2.push_back(words[i]);
                flag2 ^= 1;
            }
        }

        if (ret1.size() > ret2.size()){
            return ret1;
        }  
        else{
            return ret2;
        }
    }
};