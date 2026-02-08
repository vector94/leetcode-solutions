class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ret = 0;
        for (auto s : words){
            bool flag = true;
            for (auto x : s){
                bool flag2 = false;
                for (auto y : allowed){
                    if (x == y){
                        flag2 = true;
                    }
                }
                if (!flag2){
                    flag = false;
                    break;
                }
            }
            if (flag){
                ret++;
            }
        }
        return ret;
    }
};