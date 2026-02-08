class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> myMap;
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        myMap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        string ret = "";
        if (myMap[key].size() == 0){
            return ret;
        }
        int lo = 0;
        int hi = myMap[key].size() - 1;

        while (lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if (myMap[key][mid].second <= timestamp){
                ret = myMap[key][mid].first;
                lo = mid + 1;
            } 
            else{
                hi = mid - 1;
            }
        }
        return ret;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */