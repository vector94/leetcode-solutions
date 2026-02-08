class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, bool> canCook;
        for (string supply: supplies){
            canCook[supply] = true;
        }

        unordered_map<string, vector<string>> graph;
        for (int i = 0; i < recipes.size(); i++){
            for (int j = 0; j < ingredients[i].size(); j++){
                graph[recipes[i]].push_back(ingredients[i][j]);
            }
        }

        unordered_map<string, bool> visited;
        for (int i = 0; i < recipes.size(); i++){
            dfs(recipes[i], graph, canCook, visited);
        }

        vector<string> result;
        for (string recipe: recipes){
            if (canCook[recipe]){
                result.push_back(recipe);
            }
        }

        return result;
    }

    bool dfs(string node, unordered_map<string, vector<string>>& graph, unordered_map<string, bool>& canCook, unordered_map<string, bool>& visited){
        //cout << "First: " << node << " " << canCook[node] << endl;
        if (visited[node]){
            return canCook[node];
        }

        visited[node] = true;
        if (graph[node].size() == 0){
            return canCook[node];
        }
        else{
            bool canCookThisNode = true;
            for (int i = 0; i < graph[node].size(); i++){
                canCookThisNode &= dfs(graph[node][i], graph, canCook, visited);
            }
            canCook[node] = canCookThisNode;
        }

        //cout << node << " " << canCook[node] << endl;
        return canCook[node];
    }
};
