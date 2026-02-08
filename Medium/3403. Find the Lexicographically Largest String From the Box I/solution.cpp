class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1)    return word;
        int x = word.size() - numFriends + 1;
        
        vector<vector<int>> pos(26);
        char maxCh = 'a';

        for (int i = 0; i < word.size(); i++){
            pos[word[i] - 'a'].push_back(i);
            if (word[i] > maxCh){
                maxCh = word[i];
            }
        }

        cout << maxCh << endl;
        
        string ret = "";
        for (int i = 0; i < pos[maxCh - 'a'].size(); i++){
            int idx = pos[maxCh - 'a'][i];

            int right = min(idx + x - 1, (int)word.size() - 1);

            string curr = word.substr(idx, right - idx + 1);
            ret = max(ret, curr);
        }

        return ret;
    }
};