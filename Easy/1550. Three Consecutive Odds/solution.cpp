class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int N = arr.size();

        for (int i = 0; i + 2 < N; i++){
            if (arr[i] & 1 && arr[i + 1] & 1 && arr[i + 2] & 1){
                return true;
            }
        }

        return false;
    }
};