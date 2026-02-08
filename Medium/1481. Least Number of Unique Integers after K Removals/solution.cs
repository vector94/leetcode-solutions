public class Solution {
    public int FindLeastNumOfUniqueInts(int[] arr, int k) {
        var myDict = new Dictionary<int, int>();
        
        foreach (var n in arr){
            if (myDict.ContainsKey(n)){
                myDict[n]++;
            }
            else{
                myDict.Add(n, 1);
            }
        }
        
        var myList = new List<int>();
        foreach(var kvp in myDict){
            myList.Add(kvp.Value);
        }
        
        myList = myList.OrderBy(x => x).ToList();
        int result = 0;
        for (int i = 0; i < myList.Count; i++){
            if (myList[i] <= k){
                k -= myList[i];
            }
            else{
                result = myList.Count - i;
                break;
            }
        }
        
        return result;
    }
}
