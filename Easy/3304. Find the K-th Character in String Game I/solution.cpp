class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";

        while (word.size() < k){
            string temp;
            for (int i = 0; i < word.size(); i++){
                if (word[i] <= 'y'){
                    temp.push_back(word[i] + 1);
                }
                else{
                    temp.push_back('a');
                }
            }
            word += temp;
        }

        return word[k - 1];
    }
};