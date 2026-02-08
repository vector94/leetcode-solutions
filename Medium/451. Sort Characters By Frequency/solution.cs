public class Solution {
    public string FrequencySort(string s) {
        var freq = new Dictionary<char, int>();
        foreach (var ch in s){
            if (freq.ContainsKey(ch)){
                freq[ch]++;
            }
            else{
                freq.Add(ch, 1);
            }
        }

        var sortedFreq = freq.OrderByDescending(kv => kv.Value);
        var result = new StringBuilder();
        foreach(var kvp in sortedFreq){
            for (int i = 0; i < kvp.Value; i++){
                result.Append(kvp.Key);
            }
        }

        return result.ToString();
    }
}