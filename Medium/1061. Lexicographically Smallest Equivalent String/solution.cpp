class Solution {
public:
    int parent[26];
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for (int i = 0; i < 26; i++){
            parent[i] = i;
        }

        for (int i = 0; i < s1.size(); i++){
            unionSets(s1[i] - 'a', s2[i] - 'a');
        }

        string result = "";
        for (char ch : baseStr){
            result += (char) (find(ch - 'a') + 'a');
        }

        return result;
    }

    int find(int r){
        if (parent[r] == r){
            return r;
        }

        return find(parent[r]);
    }

    void unionSets(int a, int b){
        int u = find(a);
        int v = find(b);

        if (u == v) return;

        if (u < v){
            parent[v] = u;
        }
        else{
            parent[u] = v;
        }
    }
};