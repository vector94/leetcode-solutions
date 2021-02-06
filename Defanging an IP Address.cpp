class Solution {
public:
    string defangIPaddr(string address) {
        string ret;
        for (auto x : address){
            if (x == '.'){
                ret += "[.]";
            }
            else{
                ret.push_back(x);
            }
        }
        return ret;
    }
};
