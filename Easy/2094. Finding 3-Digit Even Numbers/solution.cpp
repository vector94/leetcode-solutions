class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> result;
        vector<int> freq(10, 0);

        for (int d : digits){
            freq[d]++;
        }

        for (int i = 100; i <= 999; i += 2){
            if (check(i, freq)){
                result.push_back(i);
            }
        }

        return result;
    }

    bool check(int n, vector<int>& freq){
        vector<int> curFreq(10, 0);

        while (n){
            curFreq[n % 10]++;
            n /= 10;
        }

        for (int i = 0; i < 10; i++){
            if (curFreq[i] == 0)    continue;
            if (curFreq[i] > freq[i]){
                return false;
            }
        }

        return true;
    }
};