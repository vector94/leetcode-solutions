class Solution {
public:
    int parent[100000];
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> andPath(n, -1);
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }

        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            int uRoot = Find(u);
            int vRoot = Find(v);

            // cout << u << " " << v << " " << uRoot << " " << vRoot << " " << andPath[uRoot] << " " << andPath[vRoot] << endl;

            andPath[uRoot] &= w;
            if (uRoot != vRoot){
                andPath[uRoot] &= andPath[vRoot];
                parent[vRoot] = uRoot;
            }
        }

        vector<int> result;

        for (int i = 0; i < query.size(); i++){
            int s = query[i][0];
            int t = query[i][1];

            if (s == t){
                result.push_back(0);
                continue;
            }
            int sRoot = Find(s);
            int tRoot = Find(t);

            if (sRoot != tRoot){
                result.push_back(-1);
            }
            else{
                result.push_back(andPath[parent[sRoot]]);
            }
        }

        return result;
    }

    int Find(int r){
        if (parent[r] == r){
            return r;
        }

        parent[r] = Find(parent[r]);
        return parent[r];
    }

};