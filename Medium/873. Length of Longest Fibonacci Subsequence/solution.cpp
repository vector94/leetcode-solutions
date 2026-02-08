class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, bool> myMap;
        for (int x : arr){
            myMap[x] = true;
        }

        int ans = 0;
        int arrSize = arr.size();
        for (int i = 0; i < arrSize; i++){
            for (int j = i + 1; j < arrSize; j++){
                int x = arr[i];
                int y = arr[j];
                int curLen = 2;
                while (true){
                    int curSum = x + y;
                    if (myMap.find(curSum) == myMap.end()){
                        break;
                    }

                    curLen++;
                    ans = max(ans, curLen);
                    x = y;
                    y = curSum;
                }
            }
        }

        return ans;
    }
};