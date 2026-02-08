class Solution {
public:
    int candy(vector<int>& ratings) {
        int N = ratings.size();

        vector<int> leftCandy(N), rightCandy(N);

        leftCandy[0] = 1;
        for (int i = 1; i < N; i++){
            if (ratings[i] > ratings[i - 1]){
                leftCandy[i] = leftCandy[i - 1] + 1;
            }
            else{
                leftCandy[i] = 1;
            }
        }

        rightCandy[N - 1] = 1;
        for (int i = N - 2; i >= 0; i--){
            if (ratings[i] > ratings[i + 1]){
                rightCandy[i] = rightCandy[i + 1] + 1;
            }
            else{
                rightCandy[i] = 1;
            }
        }

        int result = 0;
        for (int i = 0; i < N; i++){
            result += max(leftCandy[i], rightCandy[i]);
        }

        return result;
    }
};