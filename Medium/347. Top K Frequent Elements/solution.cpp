
class Solution {
     struct Data{
        int num, count;
        Data(int num, int count): num(num), count(count){}
    };

    struct compareData{
        bool operator ()(Data const& d1, Data const& d2){
            return d1.count > d2.count;
        }
    };
    priority_queue<Data, vector<Data>, compareData> myQueue;
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        for (int num : nums){
            myMap[num]++;
        }
        
        for (auto it : myMap){
            Data cur(it.first, it.second);
            myQueue.push(cur);
            if (myQueue.size() > k){
                myQueue.pop();
            }
        }
        
        vector<int> result;
        while (!myQueue.empty() > 0){
            result.push_back(myQueue.top().num);
            myQueue.pop();
        }
        
        return result;
    }
};