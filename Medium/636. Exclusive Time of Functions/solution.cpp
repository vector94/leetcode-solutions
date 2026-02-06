class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);

        stack<pair<pair<int, int>, int>> myStack;

        for (int i = 0; i < logs.size(); i++){
            vector<string> log = split(logs[i], ':');
            int id = stoi(log[0]);
            string command = log[1];
            int time = stoi(log[2]);

            if (command == "start"){
                myStack.push({{id, time}, 0});
            }
            else{
                pair<pair<int, int>, int> curFunc = myStack.top();
                myStack.pop();

                int id = curFunc.first.first;
                int startTime = curFunc.first.second;
                int endTime = time;
                int prevUsedTime = curFunc.second;

                int currentUsedTime = (endTime - startTime + 1) - prevUsedTime;
                result[id] += currentUsedTime;

                if (!myStack.empty()){
                    pair<pair<int, int>, int> prevFunc = myStack.top();
                    myStack.pop();
                    // cout << i << " " << currentUsedTime + prevUsedTime << endl;
                    prevFunc.second += currentUsedTime + prevUsedTime;
                    myStack.push(prevFunc);
                }
            }
        }

        return result;
    }

    vector<string> split(string s, char seperator){
        stringstream ss(s);
        string token;
        vector<string> tokens;

        while (getline(ss, token, seperator)){
            tokens.push_back(token);
        }

        return tokens;
    }
};