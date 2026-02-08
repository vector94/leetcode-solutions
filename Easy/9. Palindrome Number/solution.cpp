class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }
        vector<int> v;
        while (x){
            v.push_back(x % 10);
            x /= 10;
        }
        bool ret = true;
        for (int i = 0, j = v.size() - 1; i < v.size() / 2; i++, j--){
            if (v[i] != v[j]){
                ret = false;
                break;
            }
        }
        return ret;
    }
};