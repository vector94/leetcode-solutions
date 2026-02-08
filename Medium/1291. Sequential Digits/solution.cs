public class Solution {
    public IList<int> SequentialDigits(int low, int high) {
        var result = new List<int>();
        int num = 0;

        Backtrack(num, low, high, result);
        result.Sort();

        return result;
    }

    private void Backtrack(int num, int low, int high, List<int> result){
        if (num > high) return;
        if (low <= num && num <= high){
            result.Add(num);
        }

        if (num == 0){
            for (int i = 1; i <= 9; i++){
                Backtrack(i, low, high, result);
            }
        }
        else{
            int pre = num % 10;
            if (pre < 9){
                num = num * 10 + (pre + 1);
                Backtrack(num, low, high, result);
            }
        }
        return;
    }
}