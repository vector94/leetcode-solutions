class Solution {
public:
    
    int parent[30];
    
    int Find(int r){
        if (parent[r] == r){
            return r;
        }
        parent[r] = Find(parent[r]);
        return parent[r];
    }
    
    void Union(int a, int b){
        int u = Find(a);
        int v = Find(b);
        if (u != v){
            parent[u] = v;
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; i++){
            parent[i] = i;
        }
        for (string eq : equations){
            int x = eq[0] - 'a';
            int y = eq[3] - 'a';
            if (eq[1] == '='){
                Union(x, y);
            }
        }
        for (string eq : equations){
            int x = eq[0] - 'a';
            int y = eq[3] - 'a';
            if (eq[1] == '!' && Find(x) == Find(y)){
                return false;
            }
        }
        return true;
    }
};