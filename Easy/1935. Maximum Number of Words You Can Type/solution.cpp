class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        string word;

        unordered_set<char> mySet;
        for (char ch : brokenLetters){
            mySet.insert(ch);
        }

        int ans = 0;
        while (ss >> word){
            bool flag = true;
            for (int i = 0; i < word.size(); i++){
                if (mySet.find(word[i]) != mySet.end()){
                    flag = false;
                    break;
                }
            }

            if (flag)   ans++;
        }

        return ans;
    }
};