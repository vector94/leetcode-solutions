public class Solution {
    public string FirstPalindrome(string[] words) {
        foreach (var word in words){
            if (CheckPalindrome(word))
                return word;
        }
        return "";
    }
    
    private bool CheckPalindrome(string word){
        for (int i = 0, j = word.Length - 1; i < word.Length / 2; i++, j--){
            if (word[i] != word[j]) return false;
        }
        return true;
    }
}