class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> cnt(26, 0);
        for (char ch : s){
            cnt[ch - 'a']++;
        }
        
        string result;
        bool ok = true;
        while (result.size() < s.size()){
            for (int i = 25; i >= 0; i--){
                if (cnt[i] == 0)    continue;
                
                if (cnt[i] <= repeatLimit){
                    cout << i << endl;
                    for (int j = 0; j < cnt[i]; j++){
                        result.push_back(i + 'a');
                    }
                    cnt[i] = 0;
                    break;
                }
                
                else{
                    //cout << i << endl;
                    for (int j = 0; j < repeatLimit; j++){
                        result.push_back(i + 'a');
                    }
                    cnt[i] -= repeatLimit;
                    bool found = false;
                    for (int k = i - 1; k >= 0; k--){
                        if (cnt[k]){
                            cnt[k]--;
                            result.push_back(k + 'a');
                            found = true;
                            break;
                        }
                    }
                    if (!found){
                        ok = false;
                        break;
                    }
                    break;
                }
            }
            if (!ok){
                break;
            }
        }
        return result;
    }
};