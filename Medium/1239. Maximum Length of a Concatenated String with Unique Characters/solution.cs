public class Solution {
    public int MaxLength(IList<string> arr) {
        return DFS(arr, 0, 0);
    }

    private int DFS(IList<string> arr, int index, int bitmask){
        if (index == arr.Count)
            return CountBits(bitmask);

        int newBitmask = GetBitmask(arr[index]);

        if ((newBitmask & bitmask) == 0 && IsUniqueCharacter(arr[index])){
            int includeResult = DFS(arr, index + 1, bitmask | newBitmask);
            return Math.Max(includeResult, DFS(arr, index + 1, bitmask));
        }
        return DFS(arr, index + 1, bitmask);
    }

    private bool IsUniqueCharacter(string s){
        HashSet<char> charSet = new HashSet<char>();
        foreach (char ch in s){
            if (!charSet.Add(ch))
                return false;
        }
        return true;
    }

    private int GetBitmask(string s){
        int bitmask = 0;
        foreach(char ch in s){
            int bit = 1 << (ch - 'a');
            bitmask |= bit;
        }
        return bitmask;
    }

    private int CountBits(int n){
        int count = 0;
        while (n > 0){
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
}
