class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;

        int j = 0;
        for (int i = 1; i <= n; i++){
            result.push_back("Push");
            if (target[j] == i){
                j++;
                if (j == target.size()){
                    break;
                }
            }
            else{
                result.push_back("Pop");
            }
        }

        return result;
    }
};