class Solution {
public:
    vector<string> happyStrings;
    string getHappyString(int n, int k) {
        generateHappyStrings(0, "", n);

        sort(happyStrings.begin(), happyStrings.end());
        
        string kthHappyString = "";
        if (k <= happyStrings.size()){
            kthHappyString = happyStrings[k - 1];
        }

        return kthHappyString;
    }

    void generateHappyStrings(int idx, string curStr, int n){
        if (idx == n){
            happyStrings.push_back(curStr);
            return;
        }

        for (char ch = 'a'; ch <= 'c'; ch++){
            if (idx == 0 || curStr[idx - 1] != ch){
                curStr.push_back(ch);
                generateHappyStrings(idx + 1, curStr, n);
                curStr.pop_back();
            }
        }
    }
};