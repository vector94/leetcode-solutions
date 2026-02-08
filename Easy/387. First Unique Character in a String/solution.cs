public class Solution {
    public int FirstUniqChar(string s) {
        Dictionary<char, int> myDictionary = new Dictionary<char, int>();
        foreach(char ch in s){
            if (myDictionary.ContainsKey(ch)){
                myDictionary[ch]++;
            }
            else{
                myDictionary.Add(ch, 1);
            }
        }

        for (int i = 0; i < s.Length; i++){
            if (myDictionary[s[i]] == 1)   return i;
        }
        return -1;
    }
}