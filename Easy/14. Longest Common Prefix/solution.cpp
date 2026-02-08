class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret;
        if (strs.empty())   return ret;
        for (int i = 0; i < strs[0].length(); i++){
            bool flag = true;
            for (int j = 1; j < strs.size(); j++){
                if (i > strs[j].length() || strs[0][i] != strs[j][i]){
                    flag = false;
                    break;
                }
            }
            if (flag){
                ret += strs[0][i];
            }
            else{
                break;
            }
        }
        return ret;
    }
};