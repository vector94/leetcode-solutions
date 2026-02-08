class Solution {
public:
    
    string getTime(int hour, int minute){
        string s = to_string(hour);
        s.push_back(':');
        if (minute < 10){
            s.push_back('0');
        }
        s += to_string(minute);
        return s;
    }
    
    void backtrack(int currentBit, int hour, int minute, int turnedOn, vector<string> &result){
        if (turnedOn == 0){
            if (hour <= 11 && minute <= 59){
                result.push_back(getTime(hour, minute)); 
            }
            return;
        }
        for (int bit = currentBit; bit <= 9; bit++){
            if (bit <= 3){
                backtrack(bit + 1, hour | (1 << bit), minute, turnedOn - 1, result);
            }
            else{
                backtrack(bit + 1, hour, minute | (1 << (bit - 4)), turnedOn - 1, result);
            }
        }
    }
    
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        backtrack(0, 0, 0, turnedOn, result);
        return result;
    }
};