public class Solution {
    public int EvalRPN(string[] tokens) {
        Stack<int> myStack = new Stack<int>();
        int ans = 0;
        foreach(var token in tokens){
            if (token == "+" || token == "-" || token == "*" || token == "/"){
                Execute(myStack, token);
            }
            else{
                myStack.Push(int.Parse(token));
            }
        }
        return myStack.Peek();
    }

    private void Execute(Stack<int> myStack, string operation){
        int right = myStack.Pop();
        int left = myStack.Pop();
        int newVal;
        if (operation == "+") newVal = left + right;
        else if (operation == "-") newVal = left - right;
        else if (operation == "*") newVal = left * right;
        else newVal = left / right;
        myStack.Push(newVal);
    }
}