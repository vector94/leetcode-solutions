class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k){
            int cnt = 0;
            int cur_sum = 0;
            string temp;
            for (int i = 0; i < s.size(); i++){
                cur_sum += s[i] - '0';
                cnt++;

                if (cnt % k == 0){
                    temp += to_string(cur_sum);
                    cur_sum = 0;
                    cnt = 0;
                }
            }
            if (cnt > 0)    temp += to_string(cur_sum);
            s = temp;
        }

        return s;
    }
};