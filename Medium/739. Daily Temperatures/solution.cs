public class Solution {
    public int[] DailyTemperatures(int[] temperatures) {
        var myStack = new Stack<int>();
        int[] result = new int[temperatures.Length];

        for (int i = 0; i < temperatures.Length; i++){
            while (myStack.Count != 0 && temperatures[i] > temperatures[myStack.Peek()]){
                int day = myStack.Pop();
                result[day] = i - day;
            }
            myStack.Push(i);
        }

        return result;
    }
}