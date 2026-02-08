class Solution {
public:
    vector<char> signs{'+', '-', '*', '/'};
    bool flag = false;

    bool isSet(int mask, int bit){
        return (bool) (mask & (1 << bit));
    }

    int Set(int mask, int bit){
        return mask | (1 << bit);
    }

    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }
    
    double applyOperator(double a, double b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }
        return 0;
    }

    double evaluate(const string& expression){
        stack<double> values;
        stack<char> operators;

        for (int i = 0; i < expression.size(); i++){
            if (isdigit(expression[i])){
                values.push(expression[i] - '0');
            }
            else if (expression[i] == '('){
                operators.push('(');
            }
            else if (expression[i] == ')'){
                while (!operators.empty() && operators.top() != '('){
                    double b = values.top(); values.pop();
                    double a = values.top(); values.pop();
                    char op = operators.top(); operators.pop();
                    values.push(applyOperator(a, b, op));
                }
                operators.pop();
            }
            else{
                while (!operators.empty() && precedence(operators.top()) >= precedence(expression[i])){
                    double b = values.top(); values.pop();
                    double a = values.top(); values.pop();
                    char op = operators.top(); operators.pop();
                    values.push(applyOperator(a, b, op));
                }
                operators.push(expression[i]);
            }
        }

        while (!operators.empty()) {
            double b = values.top(); values.pop();
            double a = values.top(); values.pop();
            char op = operators.top(); operators.pop();
            values.push(applyOperator(a, b, op));
        }
        
        return values.top();
    }

    bool judgePoint24(vector<int>& cards) {
        flag = false;
        string expression = "";
        expression.reserve(16);
        getExpressions(0, true, false, false, true, 0, expression, cards);   
        return flag;
    }

    void getExpressions(
        int mask,
        bool canPutOpenParenthesis,
        bool canPutCloseParenthesis,
        bool canPutSign,
        bool canPutNumber,
        int numberOfOpenParenthesis,
        string& expression,
        vector<int>& cards
    ){
        if (flag) return;
        
        if (expression.size() > 15) return;
        
        if (mask == 15 && numberOfOpenParenthesis == 0) {
            if (expression.size() >= 7) {
                double result = evaluate(expression);
                if (abs(result - 24.0) < 1e-9) {
                    flag = true;
                }
            }
            return;
        }

        if (canPutNumber){
            for (int i = 0; i < 4; i++){
                if (!isSet(mask, i)){
                    expression.push_back('0' + cards[i]);
                    getExpressions(Set(mask, i), false, true, true, false, numberOfOpenParenthesis, expression, cards);
                    expression.pop_back();
                    
                    if (flag) return;
                }
            }
        }

        if (canPutSign){
            for (char sign : signs){
                expression.push_back(sign);
                getExpressions(mask, true, false, false, true, numberOfOpenParenthesis, expression, cards);
                expression.pop_back();
                
                if (flag) return;
            }
        }

        if (canPutOpenParenthesis && numberOfOpenParenthesis < 2){
            expression.push_back('(');
            getExpressions(mask, false, false, false, true, numberOfOpenParenthesis + 1, expression, cards);
            expression.pop_back();
            
            if (flag) return;
        }

        if (canPutCloseParenthesis && numberOfOpenParenthesis > 0){
            expression.push_back(')');
            getExpressions(mask, false, true, true, false, numberOfOpenParenthesis - 1, expression, cards);
            expression.pop_back();
            
            if (flag) return;
        }
    }
};