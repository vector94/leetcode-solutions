class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        
        string temp;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++){
            temp.push_back(s[i]);
            cnt++;
            
            if (cnt == k){
                result.push_back(temp);
                temp.clear();
                cnt = 0;
            }
        }
        
        if (cnt != 0){
            while (cnt < k){
                temp.push_back(fill);
                cnt++;
            }
                    
            result.push_back(temp);
        }
        return result;
    }
};