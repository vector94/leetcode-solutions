class Solution {
public:

    bool hasRelation(vector<bool> relation){
        for (auto r : relation){
            if (r)  return true;
        }
        return false;
    }

    set<int> dfs(int curNode, vector<vector<bool> > &graph, vector<vector<bool> > &relations){
        relations[curNode][curNode] = true;
        set<int> curSet;
        curSet.insert(curNode);
        for (int i = 0; i < 26; i++){
            if (relations[i][i])    continue;
            
            if (graph[curNode][i]){
                set<int> nextSet = dfs(i, graph, relations);
                for (auto it : nextSet){
                    if (curSet.find(it) == curSet.end()){
                        curSet.insert(it);
                    }
                }  
            }
        }
        for (auto it : curSet){
            relations[curNode][it] = true;
            relations[it][curNode] = true;
        }
        return curSet;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<vector<bool> > graph(26, vector<bool> (26, false));
        
        for (int i = 0; i < s1.size(); i++){
            graph[s1[i] - 'a'][s2[i] - 'a'] = true;
            graph[s2[i] - 'a'][s1[i] - 'a'] = true;
        }

        vector<vector<bool> > relations(26, vector<bool> (26, false));
        for (int i = 0; i < 26; i++){
            if (!hasRelation(relations[i])){
                dfs(i, graph, relations);
            }
        }

        string result;
        for (char ch : baseStr){
            for (int i = 0; i < 26; i++){
                if (relations[ch - 'a'][i]){
                    result.push_back('a' + i);
                    break;
                }
            }
        }

        return result;
    }
};