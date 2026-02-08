class Solution {
    map<char, string> myMap;
public:
    
    void letterCombinationsHelper(int index, string &digits, string &s, vector<string> &result){
        if (index == digits.size()){
            result.push_back(s);
            return;
        }
        
        for (char ch : myMap[digits[index]]){
            s.push_back(ch);
            letterCombinationsHelper(index + 1, digits, s, result);
            s.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        
        if (digits.size() == 0) return result;
        
        myMap['2'] = "abc";
        myMap['3'] = "def";
        myMap['4'] = "ghi";
        myMap['5'] = "jkl";
        myMap['6'] = "mno";
        myMap['7'] = "pqrs";
        myMap['8'] = "tuv";
        myMap['9'] = "wxyz";
        
        string s = "";
        
        letterCombinationsHelper(0, digits, s, result);
        return result;
    }
};