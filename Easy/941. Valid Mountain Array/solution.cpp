class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        if (arr[0] > arr[1])    return false;
        bool ret = true;
        int dir = 1;
        for (int i = 1; i < arr.size(); i++){
            if (arr[i] == arr[i - 1]){
                ret = false;
                break;
            }
            if (dir == 1){
                if (arr[i] < arr[i - 1]){
                    dir = 2;
                }
            }
            else{
                if (arr[i] > arr[i - 1]){
                    ret = false;
                    break;
                }
            }
        }
        if (dir == 1){
            ret = false;
        }
        return ret;
    }
};