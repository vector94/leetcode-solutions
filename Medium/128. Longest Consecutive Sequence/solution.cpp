class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> Index;
        unordered_map<int, bool> visited;
        
        for (int i = 0; i < nums.size(); i++){
            Index[nums[i]] = i;
            visited[i] = false;
        }
        
        int result = 0;
        for (int i = 0; i < nums.size(); i++){
            if (visited[i]){
                continue;
            }
            visited[i] = true;
            int curLength = 0;
            int j = nums[i] + 1;
            while (Index.find(j) != Index.end() && !visited[Index[j]]){
                visited[Index[j]] = true;
                j++;
            }
            curLength += j - i;
            
            j = nums[i] - 1;
            while (Index.find(j) != Index.end() && !visited[Index[j]]){
                visited[Index[j]] = true;
                j--;
            }
            curLength += i - j - 1;
            
            result = max(result, curLength);
        }
        
        return result;
    }
};

/*
hashMap = [100, 0],     [4, 1]      [200, 2],   [1, 3],     [3, 4],     [2, 5]
visited = [0, true],   [1, true]  [2, true], [3, true], [4, true], [5, true]

arr = [100,4,200,1,3,2]
*/