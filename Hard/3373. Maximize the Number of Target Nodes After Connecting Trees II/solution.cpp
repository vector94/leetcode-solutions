class Solution {
public:
    int black, white;
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int N = edges1.size() + 1;
        int M = edges2.size() + 1;

        vector<vector<int>> tree1(N);
        vector<vector<int>> tree2(M);

        for (int i = 0; i < edges1.size(); i++){
            int u = edges1[i][0];
            int v = edges1[i][1];

            tree1[u].push_back(v);
            tree1[v].push_back(u);
        }

        for (int i = 0; i < edges2.size(); i++){
            int u = edges2[i][0];
            int v = edges2[i][1];

            tree2[u].push_back(v);
            tree2[v].push_back(u);
        }

        black = white = 0;
        dfs1(-1, 0, 0, tree2);
        int bestColor = max(black, white);

        cout << bestColor << endl;

        vector<int> colors(N);
        black = white = 0;

        dfs2(-1, 0, 0, tree1, colors);

        vector<int> result;
        for (int i = 0; i < N; i++){
            int curMax;
            if (colors[i] == 0){
                curMax = white + bestColor;
            }
            else{
                curMax = black + bestColor;
            }

            result.push_back(curMax);
        }

        return result;
    }

    void dfs2(int parentNode, int curNode, int color, vector<vector<int>>& tree, vector<int>& colors){
        colors[curNode] = color;
        if (color == 0){
            white++;
        }
        else{
            black++;
        }

        for (int nextNode : tree[curNode]){
            if (nextNode == parentNode){
                continue;
            }

            dfs2(curNode, nextNode, (color + 1) % 2, tree, colors);
        }
    }

    void dfs1(int parentNode, int curNode, int color, vector<vector<int>>& tree){
        if (color == 0){
            white++;
        }
        else{
            black++;
        }

        for (int nextNode : tree[curNode]){
            if (nextNode == parentNode){
                continue;
            }

            dfs1(curNode, nextNode, (color + 1) % 2, tree);
        }
    }
};