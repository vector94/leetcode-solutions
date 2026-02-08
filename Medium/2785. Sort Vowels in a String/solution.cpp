class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<bool> isVowelIndex(n, false);
        vector<char> vowels;

        for (int i = 0; i < s.size(); i++){
            if (isVowel(s[i])){
                isVowelIndex[i] = true;
                vowels.push_back(s[i]);
            }
        }

        sort(vowels.begin(), vowels.end());
        int idx = 0;

        for (int i = 0; i < s.size(); i++){
            if (isVowelIndex[i]){
                s[i] = vowels[idx++];
            }
        }

        return s;
    }

    bool isVowel(char ch){
        ch = tolower(ch);

        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};