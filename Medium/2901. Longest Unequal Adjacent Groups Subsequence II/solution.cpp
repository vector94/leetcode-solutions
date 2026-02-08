class Solution {
public:
    int dp[1005][1005];
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int N = words.size();

        memset(dp, -1, sizeof(dp));

        int lis = solve(-1, 0, words, groups);

        cout << lis << endl;

        vector<int> indices;
        genPath(-1, 0, words, groups, indices);

        vector<string> result;
        for (int i = 0; i < indices.size(); i++){
            result.push_back(words[indices[i]]);
        }
        
        return result;
    }

    int solve(int prevIdx, int curIdx, vector<string>& words, vector<int>& groups){
        if (curIdx == words.size()){
            return 0;
        }

        if (dp[prevIdx + 1][curIdx] != -1){
            return dp[prevIdx + 1][curIdx];
        }

        int ret = solve(prevIdx, curIdx + 1, words, groups);
        if (prevIdx == -1 || (groups[prevIdx] != groups[curIdx] && check(words[prevIdx], words[curIdx]))){
            ret = max(ret, 1 + solve(curIdx, curIdx + 1, words, groups));
        }

        return dp[prevIdx + 1][curIdx] = ret;
    }

    void genPath(int prevIdx, int curIdx, vector<string>& words, vector<int>& groups, vector<int>& indices){
        if (curIdx == words.size()){
            return;
        }

        int ret1 = solve(prevIdx, curIdx + 1, words, groups);
        
        int ret2 = -1;
        if (prevIdx == -1 || (groups[prevIdx] != groups[curIdx] && check(words[prevIdx], words[curIdx]))){
            ret2 = max(ret2, 1 + solve(curIdx, curIdx + 1, words, groups));
        }

        if (ret1 >= ret2){
            genPath(prevIdx, curIdx + 1, words, groups, indices);
        }
        else{
            indices.push_back(curIdx);
            genPath(curIdx, curIdx + 1, words, groups, indices);
        }
    }

    bool check(string a, string b){
        if (a.size() != b.size())   return false;

        int dist = 0;
        for (int i = 0; i < a.size(); i++){
            if (a[i] != b[i]) dist++;
            if (dist > 1)   return false;
        }

        return dist == 1;
    }
};