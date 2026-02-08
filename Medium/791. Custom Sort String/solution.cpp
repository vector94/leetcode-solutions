class Solution {
public:
    unordered_map<char, int> myOrder;
    
    string customSortString(string order, string s) {
        for (int i = 0; i < order.size(); i++){
            myOrder[order[i]] = i;
        }
        
        sort(s.begin(), s.end(), [this](char a, char b){
            return  myOrder[a] < myOrder[b];
        });
        
        return s;
    }
};
