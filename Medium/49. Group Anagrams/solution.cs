public class Solution {
    public IList<IList<string>> GroupAnagrams(string[] strs) {
        Dictionary<string, List<string>> myDict = new Dictionary<string, List<string>>();
        foreach (string str in strs){
            var sortedString = new string(str.OrderBy(c => c).ToArray());
            if (!myDict.ContainsKey(sortedString)){
                myDict.Add(sortedString, new List<string> {str});
            }
            else{
                myDict[sortedString].Add(str);
            }
        }
        Console.WriteLine("here");
        var result = new List<IList<string>>();
        foreach(var kvp in myDict){
            result.Add(kvp.Value);
        }
        return result;
    }
}