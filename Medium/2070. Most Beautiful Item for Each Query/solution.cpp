class Solution {
public:
    
    int getBeauty(vector<pair<int, int> > &item, vector<int> &max_beauty, int query){
        int low = 0;
        int high = item.size() - 1;
        
        int ret = 0;
        
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (item[mid].first <= query){
                ret = max_beauty[mid];
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return ret;
    }
    
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        int n = items.size();
        vector<pair<int, int> > item;
        
        for (int i = 0; i < items.size(); i++){
            item.push_back({items[i][0], items[i][1]});
        }
        
        sort(item.begin(), item.end());
        
        vector<int> max_beauty(n);
        
        for (int i = 0; i < n; i++){
            if (i == 0) max_beauty[i] = item[i].second;
            else        max_beauty[i] = max(max_beauty[i - 1], item[i].second);
        }
        
        vector<int> result;
        
        for (int i = 0; i < queries.size(); i++){
            result.push_back(getBeauty(item, max_beauty, queries[i]));
        }
        
        return result;
        
    }
};