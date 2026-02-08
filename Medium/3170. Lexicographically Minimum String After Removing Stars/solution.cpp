class Solution {
public:

    struct comp{
        bool operator()(pair<char, int>& p1, pair<char, int>& p2){
            if (p1.first == p2.first){
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        }
    };

    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, comp> myQueue;

        for (int i = 0; i < s.size(); i++){
            if (s[i] == '*'){
                int idx = myQueue.top().second;
                myQueue.pop();
                s[idx] = '*';
                continue;
            }

            myQueue.push({s[i], i});
        }

        string result;
        for (int i = 0; i < s.size(); i++){
            if (s[i] != '*'){
                result.push_back(s[i]);
            }
        }

        return result;
    }
};