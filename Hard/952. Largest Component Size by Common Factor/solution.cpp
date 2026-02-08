class Solution {
public:
    
    int Find(int a, vector<int> &parent){
        if (parent[a] == -1)    return a;
        parent[a] = Find(parent[a], parent);
        return parent[a];
    }
    
    void Union(int a, int b, vector<int> &parent){
        int u = Find(a, parent);
        int v = Find(b, parent);
        if (u != v){
            parent[u] = v;
        }
    }
    
    
    int largestComponentSize(vector<int>& nums) {
        
        vector<int> parent(100005, -1);
        
        for (int i = 0; i < nums.size(); i++){
            for (int j = 2; j <= sqrt(nums[i]); j++){
                if (nums[i] % j == 0){
                    Union(nums[i], j, parent);
                    Union(nums[i], nums[i] / j, parent);
                }
            }
        }
        
        map<int, int> components;
        
        for (int i = 0; i < nums.size(); i++){
            components[Find(nums[i], parent)]++;
        }
        
        int result = 0;
        
        for (auto it : components){
            result = max(result, it.second);
        }
        
        return result;
    }
};