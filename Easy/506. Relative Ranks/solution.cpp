class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sortedScore = score;
        
        sort(sortedScore.begin(), sortedScore.end(), greater<int>());
        unordered_map<int, int> rank;
        
        for (int i = 0; i < sortedScore.size(); i++){
            rank[sortedScore[i]] = i + 1;
        }
        
        vector<string> result;
        for (int s : score){
            if (rank[s] == 1){
                result.push_back("Gold Medal");
            }
            else if (rank[s] == 2){
                result.push_back("Silver Medal");
            }
            else if (rank[s] == 3){
                result.push_back("Bronze Medal");
            }
            else{
                result.push_back(to_string(rank[s]));
            }
        }
        
        return result;
    }
};