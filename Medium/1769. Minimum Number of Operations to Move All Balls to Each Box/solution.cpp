class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> result(n);
        
        int move = 0;
        int box = 0;
        for (int i = 0; i < n; i++){
            move += box;
            result[i] = move;
            box += (boxes[i] == '1');
        }
        move = box = 0;
        for (int i = n - 1; i >= 0; i--){
            move += box;
            result[i] += move;
            box += (boxes[i] == '1');
        }
        return result;
    }
};