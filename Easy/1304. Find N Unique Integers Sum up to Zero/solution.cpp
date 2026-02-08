class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;

        int num = 1;
        while (n > 1){
            result.push_back(num);
            result.push_back(num * -1);
            n -= 2;
            num++;
        }

        if (n){
            result.push_back(0);
        }

        return result;
    }
};