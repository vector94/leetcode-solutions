class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int N = arr.size();

        vector<pair<int, int>> myVec;
        for (int i = 0; i < N; i++){
            myVec.push_back({arr[i], i});
        }

        sort(myVec.begin(), myVec.end());

        vector<int> result(N);
        int rank = 1;

        for (int i = 0; i < N; i++){
            if (i > 0 && myVec[i].first != myVec[i - 1].first){
                rank++;
            }

            result[myVec[i].second] = rank;
        }

        return result;
    }
};