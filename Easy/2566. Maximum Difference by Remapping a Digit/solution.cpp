class Solution {
public:
    int minMaxDifference(int num) {
        int maxNum = getMaxNum(num);
        int minNum = getMinNum(num);

        return maxNum - minNum;
    }

    int getMaxNum(int n){
        int maxNum = 0;
        for (char ch = '0'; ch <= '8'; ch++){
            maxNum = max(maxNum, getReplacedNum(n, ch, '9'));
        }

        return maxNum;
    }

    int getMinNum(int n){
        int minNum = INT_MAX;
        for (char ch = '1'; ch <= '9'; ch++){
            minNum = min(minNum, getReplacedNum(n, ch, '0'));
        }

        return minNum;
    }

    int getReplacedNum(int n, char from, char to){
        string num = to_string(n);

        for (int i = 0; i < num.size(); i++){
            if (num[i] == from){
                num[i] = to;
            }
        }

        return stoi(num);
    }
};