class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod = 1e9 + 7;
        int result = 0;
        
        for (int i = 0; i < arr.size(); i++){
            vector<int> count(101, 0);
            for (int j = i + 1; j < arr.size(); j++){
                int k = target - arr[i] - arr[j];
                if (k < 0 || k > 100)   continue;

                result += count[k];
                result %= mod;
                
                count[arr[j]]++;
            }
        }
        
        return result;
    }
};