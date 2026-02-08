class Solution {
public:
    string countAndSay(int n) {
        if (n == 1){
            return "1"; 
        }
        string ret = "1";
        for (int i = 2; i <= n; i++){
            string temp;
            for (int i = 0; i < ret.size(); i++){
                char cur = ret[i];
                int cnt = 0;
                while (ret[i] == cur && i < ret.size()){
                    cnt++;
                    i++;
                }
                i--;
                temp += to_string(cnt);
                temp += cur;
            }
            ret = temp;
        }
        return ret;
    }
};