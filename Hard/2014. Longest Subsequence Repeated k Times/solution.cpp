class Solution {
public:

    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> freq(26, 0);
        for (char ch : s){
            freq[ch - 'a']++;
        }

        string result = "";

        queue<string> myQueue;
        for (char ch = 'a'; ch <= 'z'; ch++){
            if (freq[ch - 'a'] >= k){
                string x;
                x.push_back(ch);
                myQueue.push(x);
            }
        }

        while (!myQueue.empty()){
            string curSeq = myQueue.front();
            myQueue.pop();

            result = curSeq;

            for (char ch = 'a'; ch <= 'z'; ch++){
                string nextSeq = curSeq;
                nextSeq.push_back(ch);

                if (check(s, nextSeq, k)){
                    myQueue.push(nextSeq);
                }
            }
        }

        return result;
    }

    bool check(string& s, string& subSeq, int k){
        int cnt = 0;
        int subIdx = 0;

        for (int i = 0; i < s.size(); i++){
            if (s[i] == subSeq[subIdx]){
                subIdx++;
                if (subIdx == subSeq.size()){
                    subIdx = 0;
                    cnt++;

                    if (cnt >= k)   return true;
                }
            }
        }

        return false;
    }
};