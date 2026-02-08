class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int N = weights.size();
        vector<int> edgeWeights;

        for (int i = 0; i < N - 1; i++){
            edgeWeights.push_back(weights[i] + weights[i + 1]);
        }

        sort(edgeWeights.begin(), edgeWeights.end());

        long long ans = 0;
        for (int i = 0; i < k - 1; i++){
            ans += edgeWeights[N - 2 - i] - edgeWeights[i];
        }

        return ans;
    }
};