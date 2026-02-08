class Solution {
public:
    vector<int> partitionLabels(string s) {
        int N = s.size();
        unordered_map<char, int> leftMostIndex;
        vector<int> indexArray(N);

        for (int i = N - 1; i >= 0; i--){
            if (leftMostIndex[s[i]] == 0){
                leftMostIndex[s[i]] = i;
            }

            indexArray[i] = leftMostIndex[s[i]];
        }

        int left = 0;
        int right = -1;
        vector<int> result;

        for (int i = 0; i < N; i++){
            right = max(right, leftMostIndex[s[i]]);

            if (i == right){
                result.push_back(i - left + 1);
                left = i + 1;
            }
        }

        return result;
    }
};