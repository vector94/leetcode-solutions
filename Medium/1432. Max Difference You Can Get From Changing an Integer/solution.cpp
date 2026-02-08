class Solution {
public:
    int maxDiff(int num) {
        int maxNum = 0;
        int minNum = INT_MAX;

        for (char from = '0'; from <= '9'; from++){
            for (char to = '0'; to <= '9'; to++){
                if (from == to){
                    continue;
                }

                int curNum = getReplacedNum(num, from, to);
                if (curNum == -1)    continue;

                maxNum = max(maxNum, curNum);
                minNum = min(minNum, curNum);
            }
        }

        cout << maxNum << " " << minNum << endl;
        return maxNum - minNum;
    }

    int getReplacedNum(int n, char from, char to){
        string num = to_string(n);

        for (int i = 0; i < num.size(); i++){
            if (num[i] == from){
                num[i] = to;
            }
        }
        if (num[0] == '0')  return -1;
        return stoi(num);
    }
};