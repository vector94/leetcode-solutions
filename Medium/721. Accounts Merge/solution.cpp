class UnionFind{
    int groupCount;
    vector<int> parent;
    
public:
    UnionFind(int n){
        groupCount = n;
        parent = vector<int> (n);
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    
    int getGroupCount(){
        return groupCount;
    }
    
    int Find(int p){
        if (parent[p] == p){
            return p;
        }
        parent[p] = Find(parent[p]);
        return parent[p];
    }
    void Union(int a, int b){
        int u = Find(a);
        int v = Find(b);
        
        if (u != v){
            parent[u] = v;
            groupCount--;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int accountsCount = accounts.size();
        UnionFind uf(accountsCount);
        
        unordered_map<string, int> emailToIndex;
        
        for (int i = 0; i < accountsCount; i++){
            for (int j = 1; j < accounts[i].size(); j++){
                string email = accounts[i][j];
                
                if (emailToIndex.find(email) == emailToIndex.end()){
                    emailToIndex[email] = i;
                }
                else{
                    uf.Union(i, emailToIndex[email]);
                }
            }
        }
        
        int mergedAccountsCount = uf.getGroupCount();
        vector<vector<string> > result(mergedAccountsCount);
        unordered_map<int, int> groupIdToIdx;
        int nextIdx = 0;
        for (auto it : emailToIndex){
            string email = it.first;
            int groupId = uf.Find(it.second);
            
            if (groupIdToIdx.find(groupId) == groupIdToIdx.end()){
                groupIdToIdx[groupId] = nextIdx;
                result[nextIdx].push_back(accounts[groupId][0]);
                result[nextIdx].push_back(email);
                nextIdx++;
            }
            else{
                int curIdx = groupIdToIdx[groupId];
                result[curIdx].push_back(email);
            }
        }
        
        for (int i = 0; i < mergedAccountsCount; i++){
            sort(result[i].begin() + 1, result[i].end());
        }
        
        return result;
        
    }
};