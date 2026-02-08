class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> visit;
        for (string word: wordList){
            visit[word] = false;
        }
        
        int result = 0;
        queue<string> myQueue;
        myQueue.push(beginWord);
        
        while (!myQueue.empty()){
            result++;
            int cnt = myQueue.size();
            for (int i = 0; i < cnt; i++){
                string cur = myQueue.front();
                myQueue.pop();
                if (cur == endWord){
                    return result;
                }
                for (int j = 0; j < cur.size(); j++){
                    string next = cur;
                    for (int k = 0; k < 26; k++){
                        next[j] = 'a' + k;
                        if (visit.find(next) != visit.end() && !visit[next]){
                            myQueue.push(next);
                            visit[next] = true;
                        }
                    }
                }
            }
        }
        return 0;
    }
};