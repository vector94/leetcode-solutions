class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if (flowerbed.size() == 1 && flowerbed.back() == 0) return true;
        
        for (int i = 0; i < flowerbed.size(); i++){
            if (n == 0) return true;
            
            if (flowerbed[i] == 1)  continue;
            
            if (i == 0 && i + 1 < flowerbed.size() && flowerbed[i + 1] == 0){
                n--;
                i++;
            }
            else if (i == flowerbed.size() - 1 && i - 1 >= 0 && flowerbed[i - 1] == 0){
                n--;
                i++;
            }
            else if (i > 0 && i + 1 < flowerbed.size() && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0){
                n--;
                i++;
            }
        }
        
        return (n == 0);
    }
};