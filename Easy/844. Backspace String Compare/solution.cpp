class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int bs, bt;
        bs = bt = 0;
        
        int i = s.size() - 1;
        int j = t.size() - 1;
        
        while (i >= 0 || j >= 0){
            bool flag1, flag2;
            flag1 = flag2 = true;
            
            if (bs || (i >= 0 && s[i] == '#')){
                flag1 = false;
                if (i >= 0 && s[i] == '#'){
                    bs++;
                }
                else{
                    bs--;
                }
                i--;
            }
            
            if (bt || (j >= 0 && t[j] == '#')){
                //cout << i << " " << j << endl;
                flag2 = false;
                if (j >= 0 && t[j] == '#'){
                    bt++;
                }
                else{
                    bt--;
                }
                j--;
            }
            
            if (flag1 && flag2){
                if (i < 0 || j < 0) return false;
                if (s[i] == t[j]){
                    i--;
                    j--;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};

