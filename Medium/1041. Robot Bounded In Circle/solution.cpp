class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dx, dy;
        dx = 0, dy = 1;
        
        int x, y;
        x = y = 0;
        
        for (int i = 0; i <  instructions.size(); i++){
            if (instructions[i] == 'G'){
                x += dx;
                y += dy;
            }
            else if (instructions[i] == 'L'){
                swap(dx, dy);
                dx *= -1;
            }
            else{
                swap(dx, dy);
                dy *= -1;
            }
        }
        
        return (x == 0 && y == 0) || (dx != 0 || dy != 1); 
    }
};
