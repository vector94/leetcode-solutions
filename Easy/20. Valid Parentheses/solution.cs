public class Solution {
    
    public bool bracketChecker(char open, char close){
        return (open == '(' && close == ')' || open == '{' && close == '}' || open == '[' && close == ']');
    }
    
    public bool IsValid(string s) {
        
        Stack<char> myStack = new Stack<char>();
        
        for (int i = 0; i < s.Length; i++){
            
            if (s[i] == '(' || s[i] == '{' || s[i] == '['){
                myStack.Push(s[i]);
            }
            
            else{
                
                if (myStack.Count == 0 || !bracketChecker(myStack.Peek(), s[i])){
                    return false;
                }
                
                myStack.Pop();
            }
        }
        
        if (myStack.Count > 0)  return false;
        return true;
    }
}