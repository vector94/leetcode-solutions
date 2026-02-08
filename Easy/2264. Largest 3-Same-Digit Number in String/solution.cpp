class Solution {
public:
    string largestGoodInteger(string num) {
        int maxNum = -1;
        string ans = "";

        for (int i = 0; i < num.size() - 2; i++){
            if (num[i] != num[i + 1] || num[i + 1] != num[i + 2])   continue;
            string curNumStr;
            curNumStr.push_back(num[i]);
            curNumStr.push_back(num[i + 1]);
            curNumStr.push_back(num[i + 2]);
            int curNum = stoi(curNumStr);
            if (curNum > maxNum){
                ans = curNumStr;
                maxNum = curNum;
            }
        }

        return ans;
    }
};