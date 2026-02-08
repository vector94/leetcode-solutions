class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits.back() == 1)   return false;

        bits.pop_back();

        for (int i = 0; i < bits.size(); i++){
            if (bits[i] == 1){
                if (i + 1 == bits.size())   return false;
                i++;
            }
        }

        return true;
    }
};