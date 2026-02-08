class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumedBottles = 0;

        while (numBottles >= numExchange){
            int cnt = numBottles / numExchange;

            consumedBottles += numExchange * cnt;
            numBottles -= numExchange * cnt;

            numBottles += cnt;
        }

        return consumedBottles + numBottles;
    }
};