class RandomizedSet {
private:
    unordered_map<int, int> hashMap;
    vector<int> myList;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (hashMap.find(val) != hashMap.end()){
            return false;
        }
        myList.push_back(val);
        hashMap[val] = myList.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (hashMap.find(val) == hashMap.end()){
            return false;
        }
        myList[hashMap[val]] = myList.back();
        hashMap[myList.back()] = hashMap[val];
        myList.pop_back();
        hashMap.erase(val);
        return true;
    }
    
    int getRandom() {
        return myList[rand() % myList.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */