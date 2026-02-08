class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        bool ret = false;
        for (int i = 0; i < arr.size(); i++){
            for (int j = i + 1; j < arr.size(); j++){
                if (arr[i] == arr[j] * 2 || arr[i] * 2 == arr[j]){
                    ret = true;
                }
            }
        }
        return ret;
    }
};