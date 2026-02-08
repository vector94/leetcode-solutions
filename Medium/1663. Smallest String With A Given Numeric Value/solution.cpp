class Solution {
public:
    string getSmallestString(int n, int k) {
        string result;
        for (int i = 1; i <= n; i++){
            if (i == n){
                result.push_back('a' + k - 1);
            }
            else if ((k + (n - i - 1)) / (n - i) <= 26){
                k--;
                result.push_back('a');
            }
            else{
                int toAdd = k % 26 == 0 ? 26 : k % 26;
                k -= toAdd;
                result.push_back('a' + toAdd - 1);
            }
        }
        return result;
    }
};