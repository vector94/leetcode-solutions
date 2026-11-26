class Solution {
public:
    bool canAliceWin(int n) {
        if (n < 10) return false;

        n -= 10;
        int prev = 10;
        int turn = 1;

        while (true){
            if (n >= prev - 1){
                n -= (prev - 1);
                prev--;
            }
            else{
                break;
            }
            turn ^= 1;
        }

        return (bool)turn;
    }
};