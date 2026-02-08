class Solution {
public:
    unordered_map<int, int> myMap;

    int nextBeautifulNumber(int n) {
        while (++n){
            if (isNumericallyBalanced(n)){
                return n;
            }
        }
        return 0;
    }

    bool isNumericallyBalanced(int n){

        myMap.clear();

        while (n){
            myMap[n % 10]++;
            n /= 10;
        }

        for (auto it : myMap){
            int num = it.first;
            int value = it.second;

            if (num != value)   return false;
        }

        return true;
    }
};