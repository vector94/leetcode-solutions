class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> asString;
        for (int n : nums){
            asString.push_back(to_string(n));
        }
        
        sort(asString.begin(), asString.end(), [](string a, string b){
           return a + b > b + a; 
        });
        
        string result = "";
    
        for (string s : asString){
            result += s;
        }
        if (result[0] == '0')   result = "0";
        return result;
    }
};