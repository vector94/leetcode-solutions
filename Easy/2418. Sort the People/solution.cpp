class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string, int>> peoples;

        for (int i = 0; i < names.size(); i++){
            peoples.push_back({names[i], heights[i]});
        }

        sort(peoples.begin(), peoples.end(),
            [] (pair<string, int> a, pair<string, int> b){
                return a.second > b.second;
            }
        );
        vector<string> ret;
        for (int i = 0; i < peoples.size(); i++){
            ret.push_back(peoples[i].first);
        }

        return ret;
    }
};